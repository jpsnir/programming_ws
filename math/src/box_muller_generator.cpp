#include <cmath>
#include <cuda.h>
#include <curand_kernel.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>

#define N 100000
/*
 * Program to generate normally distributed random numbers from box muller
 * method in CPU and GPU
 */
int main() {
  std::random_device rd;
  std::mt19937 mt(rd());
  auto condition = [](double d, double min, double max) -> bool {
    return (d > min && d <= max);
  };
  double binSize = 0.1;
  std::map<double, int> histogram{};
  for (int i = 0; i < N; i++) {
    double u = mt();
    double u_01 = u / UINT_MAX;
    double min = 0;
    while (min <= 1.0f) {
      double max = min + binSize;
      if (condition(u_01, min, min + binSize))
        ++histogram[min];
      min = max;
    }
  }

  for (auto [x, y] : histogram)
    std::cout << std::setw(2) << x << ' ' << std::string(y / 200, '*') << '\n';

  std::mt19937 gen1(rd());
  std::mt19937 gen2(rd());
  constexpr double TWO_PI = 2.0 * M_PI;
  std::uniform_real_distribution<double> u_dist1(0, 1);
  std::uniform_real_distribution<double> u_dist2(0, 1);
  auto Z0 = [&gen1, &gen2](double u1, double u2) -> double {
    return sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
  };
  auto Z1 = [&gen1, &gen2](double u1, double u2) -> double {
    return sqrt(-2 * log(u1)) * sin(2 * M_PI * u2);
  };
  binSize = 0.5;
  histogram.clear();
  for (int i = 0; i < N; i++) {
    double u1 = u_dist1(gen1);
    double u2 = u_dist2(gen2);
    double min = -4;
    double z0 = Z0(u1, u2);
    while (min <= 4.0f) {
      double max = min + binSize;
      if (condition(z0, min, min + binSize))
        ++histogram[min];
      min = max;
    }
  }
  std::cout << std::string(10, '-') << std::endl;
  for (auto &pair : histogram)
    std::cout << std::setw(2) << pair.first << ' ' << std::string(pair.second / 200, '*') << '\n';
}

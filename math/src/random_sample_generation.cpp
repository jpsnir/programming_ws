#include <iostream>
#include <random>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>


/*
 * Random number generation
 * Different ways
 */
std::vector<int> createHistogram(const std::vector<double>& data, int numBins) {
    // Find the minimum and maximum values in the data
    double minValue = *min_element(data.begin(), data.end());
    double maxValue = *max_element(data.begin(), data.end());

    // Calculate the range of the data
    double range = maxValue - minValue + 1;

    // Calculate the width of each bin
    double binWidth = static_cast<double>(range) / numBins;

    // Initialize the histogram with zeros
    std::vector<int> histogram(numBins, 0);

    // Populate the histogram by counting data points in each bin
    for (int value : data) {
        int binIndex = static_cast<int>((value - minValue) / binWidth);
        if (binIndex >= 0 && binIndex < numBins) {
            histogram[binIndex]++;
        }
    }

    return histogram;
}

double exponetial_pdf(double x, double lambda){
    return lambda*exp(-lambda*x);
}

double inv_cdf(double u, double lambda) {
    return -log(1 - u)/lambda;
}

int main() {
    double lambda = 0.5;
    int num_samples = 10000;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> uniform_dist(0.0, 1.0);

    std::vector<double> src_dist_data, tgt_dist_data;
    double sum1 = 0, sum2 = 0;
    for(int i = 0; i < num_samples; ++i){
        double u = uniform_dist(gen);
        double x = inv_cdf(u, lambda);
        tgt_dist_data.push_back(x);
        src_dist_data.push_back(u);
        sum1 = sum1 + u;
        sum2 = sum2 + x;
        //std::cout << "Sample " << i+1 << ": " << x << std::endl;
    }

    std::cout << " mean of uniform samples: " << sum1/num_samples << std::endl;
    std::cout << " mean of exponential samples: " << sum2/num_samples << std::endl;

    int numBins = 100;
    std::vector<int> histogram = createHistogram(tgt_dist_data,100);
 //   for (int i = 0; i < numBins; i++) {
 //       int binStart = i * (tgt_dist_data.size() / numBins);
 //       int binEnd = (i == numBins - 1) ? tgt_dist_data.size() : (i + 1) * (tgt_dist_data.size() / numBins);
 //       std::cout << "Bin " << i + 1 << ": " << histogram[i] << " ("
 //                 << "Range: " << binStart << " - " << binEnd - 1 << ")" << std::endl;
 //   }

}

#include <cmath>
#include <iostream>
#include <limits.h>
/*
 */

int main() {
  int stages = 4, min;
  int n = 8; // no. of graph nodes.
  int cost[9] = {0,0,0,0,0,0,0,0}, d[9] = {0,0,0,0,0,0,0,0,0}, p[9];
  int c[9][9] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 4, 7, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 3, 8, 0, 0, 0}, {0, 0, 0, 0, 3, 2, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 6, 5, 0}, {0, 0, 0, 0, 0, 0, 5, 8, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 9}, {0, 0, 0, 0, 0, 0, 0, 0, 10},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
  };

  // start from rear end to tabulate
  for (int i = n - 1; i >= 1; i--) {
    min = INT_MAX;
    for (int k = i + 1; k <= n; k++) {

      if (c[i][k] != 0 && c[i][k] + cost[k] < min) {
        min = c[i][k] + cost[k];
        d[i] = k;
      }
      cost[i] = min;
    }
  }
  p[1] = 1;
  p[stages] = n;
  for (int i = 0; i <= n; i++) {
    std::cout << " cost : [" << i << "]: " << cost[i] << "\n";
    std::cout << " destination : [" << i << "] : " << d[i] << "\n";
  }
}

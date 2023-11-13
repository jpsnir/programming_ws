#include <iostream>
#include <limits.h>
#include <cmath>

/* All pair shortest path.
 * If you use Djiktra algorithm, the steps will be O(n^2) * n
 * INT_MAX is assigned when the path to that matrix does not exist. No edge.
 * An edge to itself is shown as zero .
 * Floyd Warshall algorithm - uses dynamic programming.
 */
int main(){
    int A[4][4] = {{0, 3, INT_MAX, 7},
                 {8, 0, 2, INT_MAX},
                 {5, INT_MAX, 0, 1},
                 {2, INT_MAX, INT_MAX, 0},
    };
    int n = 4;
    int A_[n][n][n];
    for (int k=1; k <= n; k++){
        for(int i = 1; i<= n; i++){
            for (int j = 1; j <= n; j++){
                A_[k][i][j] = std::min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }

}

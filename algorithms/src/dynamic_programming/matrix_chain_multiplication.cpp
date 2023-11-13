#include <iostream>
#include <limits.h>

/* Generally a matrix M (mxn) and a matrix P (nxp), the total number
 * of multiplications are mxnxp. As for each element we have multiply a row of
 * size n with column of size n, giving me n multiplications, and then the
 * number of elements are mxp giving me mxnxp multiplications.
 * Now we want to reduce the number of multiplications by choosing the way we
 * multiply the
 *
 * Solving the paranthesis problem for matrix chain multiplication is O(n^3)
 * where n is the number of matrices.
 *
 * Matrix multiplication is also n^3 where n is the number of rows of matrix.
 */

int main(){
    int n = 5;
    int p[] = {5,4,6,2,7};
    int m[5][5] = {0};
    int s[5][5] = {0};
    int j, min, q;

    // difference of matrix index
    for(int d=1; d <n-1; d++){
        for(int i = 1; i <n-d; i++){
            j = i+d;
            int min = INT_MAX;
            for(int k = 1; k<= j-1; k++){
                int q =  m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < min){
                    min = q;
                    s[i][j] = k;
                }
                m[i][j] = min;
            }
            std::cout << m[1][n-1];
        }
    }
}

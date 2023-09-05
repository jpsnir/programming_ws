#include <iostream>
#include <cmath>
#include <cuda.h>
#include <cuda_runtime.h>

/* cuda program to copy matrices to cuda memory and add each element
 * We want to index the matrices with [][] notation as opposed to
 * linear referencing using single bracket []
 */

#define N 10

//cuda kernel for addition of matrix using linear memory
__global__ void  matrix_add_linear(float *a, float *b, float*c){

    //each element to be added by different thread.
    int i = blockDim.x*blockIdx.x + threadIdx.x;
    if (i < N*N )
        c[i] = a[i] + b[i];

}

/* initialize a square diagnoal matrix with value provided.
   global matrices are passed as pointers.
 */

void initialize_diagonal_matrix(float **h_aa, int diag_elem){
    int value;
    for (int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (i==j){
                value = diag_elem;
            }
            else{
                value = 0;
            }
            h_aa[i][j] = value;
        }
    }
}


int main(void){
    // allocate host memory for matrices
    int rows = N , cols = N;

    // allocate space of array in a linear fashion
    float *h_a, *h_b, *h_c;
    h_a = (float*)malloc(rows*cols*sizeof(float));
    h_b = (float*)malloc(rows*cols*sizeof(float));
    h_c = (float*)malloc(rows*cols*sizeof(float));

    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int value1, value2;
            if (i==j){
                value1 = 2;
                value2 = 3;
            }
            else{
                value1 = 0;
                value2 = 0;
            }

            h_a[rows*i+j] = value1;
            h_b[rows*i+j] = value2;
        }
    }

    float *d_a, *d_b, *d_c;
    //Allocate on cuda device
    // d_a is a pointer on host device and is
    // storing a pointer value on the GPU device
    cudaMalloc((void**)&d_a,sizeof(float)*rows*cols);
    cudaMalloc((void**)&d_b, sizeof(float)*rows*cols);
    cudaMalloc((void**)&d_c, sizeof(float)*rows*cols);

    cudaMemcpy(d_a, h_a, sizeof(float)*rows*cols,cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, sizeof(float)*rows*cols,cudaMemcpyHostToDevice);
    int blocksize = N;
    int thread_numbers = N;
    matrix_add_linear<<<blocksize, thread_numbers>>>(d_a, d_b, d_c);
    cudaMemcpy(h_c, d_c,sizeof(float)*rows*cols,cudaMemcpyDeviceToHost);

    for(int i = 0; i < rows; i++ ){
        for(int j = 0; j < cols; j++){
            std::cout << h_c[rows*i+j] << ", " ;
        }
        std::cout << std::endl;
    }

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    free(h_a);
    free(h_b);
    free(h_c);

    float **h_aa,**h_bb, **h_cc;
    initialize_diagonal_matrix(h_aa, 5);
    initialize_diagonal_matrix(h_bb, 10);
    float *d_ma, *d_mb, *d_mc;
    size_t pitch;
    cudaMallocPitch(&d_ma, &pitch, cols*sizeof(float), rows);
    cudaMemcpy2D(d_ma,pitch,h_aa,cols*sizeof(float),cols*sizeof(float),rows,cudaMemcpyDeviceToHost);

    exit(0);

}

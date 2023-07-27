/*
 * Vector addtion using cuda and cpu
 * @ author: jagatpreet
 * adapted from: https://github.com/puttsk/cuda-tutorial/tree/master/tutorial01
 */
#include <cstdio>
#include <cmath>
#include <iostream>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define N 10000000
#define MAX_ERR 1e-6
__global__ void cuda_add(float *out, float *a, float *b, int n){
    for (int i =0; i < n; i++){
        out[i] = a[i] + b[i];
    }
}
void vector_add(float *out, float *a, float *b, int n){
    for(int i = 0; i < n; i ++){
       out[i] = a[i] + b[i];
    }
}

int main() {
    float *a, *b, *out;

    //Reserve memory
    a = (float*)malloc(sizeof(float)*N);
    b = (float*)malloc(sizeof(float)*N);
    out = (float*)malloc(sizeof(float)*N);

    // assign values
    for (int i=0; i < N ; i++){
        a[i] = 1.0f; b[i] = 3.3f;
    }
    vector_add(out, a, b, N);


    float *d_a, *d_b, *d_out; // stores device allocation pointer
    // allocate on cuda device
    cudaMalloc((void**)&d_a, sizeof(float)*N);
    cudaMalloc((void**)&d_b, sizeof(float)*N);
    cudaMalloc((void**)&d_out, sizeof(float)*N);
    cudaMemcpy(d_a, a, sizeof(float)*N, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, sizeof(float)*N, cudaMemcpyHostToDevice);

    cuda_add<<<1,1>>>(d_out, d_a, d_b, N);

    cudaMemcpy(out, d_out, sizeof(float)*N, cudaMemcpyDeviceToHost);
    for (int i=0; i < N; i++){
        //printf("output = %f", out[i]);
        assert(fabs(out[i] - a[i] - b[i]) < MAX_ERR);
    }

    printf("out[0] = %f \n", out[0]);
    printf("Passed \n");
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_out);

    // deallocate host memory
    free(a);
    free(b);
    free(out);


}

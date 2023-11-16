#include <cuda.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

__global__ void addVector(float *x, float *y, float *z){
    int i = threadIdx.x;
    printf("block id = %d \n", blockIdx.x);
    printf("thread Idx = %d \n", i);
    z[i] = x[i] + y[i];
}
__global__ void addMatrix(float *x, float *y, float *z){
    int row = threadIdx.x;
    int col = threadIdx.y;

    printf("thread Idx = %d, %d \n", row, col);
    int index = row*16 + col;
    z[index] = x[index] + y[index];
}

int main(void){
    // pointers to the host data.
    float *x, *y, *z;

    // pointers to the device data
    float *d_x, *d_y, *d_z;

    // No. data elements to be processed
    int N = 1<<8; // 256
    std::cout << " N = " << N << std::endl;

    //assign memory in the device
    // ? not sure whether it will use global memory, DRAM etc. on GPU.
    cudaMalloc((void**)&d_x, sizeof(float)*N);
    cudaMalloc((void**)&d_y, sizeof(float)*N);
    cudaMalloc((void**)&d_z, sizeof(float)*N);

    // new returns a pointer of type float
    // to first element
    //
    // we could have used malloc function, which returns a null pointer.
  //  x = new float(N);
  //  y = new float(N);
  //  z = new float(N);
    x = (float*)malloc(sizeof(float)*N);
    y = (float*)malloc(sizeof(float)*N);
    z = (float*)malloc(sizeof(float)*N);
    for(int i = 0; i < N; i ++){
        x[i] = 1.0f;
        y[i] = 1.0f;
    }
    // copy data to allocated variables on GPU.
    cudaMemcpy(d_x, x, sizeof(float)*N, cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, sizeof(float)*N, cudaMemcpyHostToDevice);

    // In this example, we are using
    // memory on the GPU device for computation.
    addVector<<<1, 256>>>(d_x, d_y, d_z);

    // 2d block of threads
    dim3 threadMatBlock(16, 16);
    addMatrix<<<1, threadMatBlock>>>(d_x, d_y, d_z);

    // copy result back
    cudaMemcpy(z, d_z, sizeof(float)*N, cudaMemcpyDeviceToHost);
    std::cout << " Z[10] " << z[10] << std::endl;
    std::cout << " Z[100] " << z[100] << std::endl;
    std::cout << " Z[255] " << z[255] << std::endl;
    cudaFree(d_x); cudaFree(d_y); cudaFree(d_z);
    exit(0);
}

#include <iostream>
#include <cmath>
#include <cuda.h>

void add_on_cpu(int n, float *x, float *y){
    for(int i=0; i < n; i++){
        y[i] = x[i] + y[i];
    }
}

// cuda kernel
__global__ void add_on_gpu(int n, float *x, float *y){
    int t_index = blockIdx.x*blockDim.x + threadIdx.x;
    int stride = blockDim.x*gridDim.x;
    for(int data_index=t_index; data_index < n; data_index+=stride){
        y[data_index] = x[data_index] + y[data_index];
    }
}

int main(void){
    int N = 1<<20;
    std::cout<<"N = "<<N<<std::endl;
    //allocate on heap
    float *x = new float[N];
    float *y = new float[N];
    float *x_gpu, *y_gpu;

    cudaMallocManaged(&x_gpu, N*sizeof(float));
    cudaMallocManaged(&y_gpu,N*sizeof(float));
    int value, dev_id=0;
    cudaDeviceGetAttribute(&value, cudaDevAttrMultiProcessorCount, dev_id);
    std::cout << "Number of streaming processors : " << value << std::endl;
    cudaDeviceGetAttribute(&value, cudaDevAttrMaxThreadsPerBlock, dev_id);
    std::cout << "Number of threads per block : " << value << std::endl;
    int blocksize = 256;
    int numblocks = N / blocksize;
    std::cout << " N = " << N << ", Number of blocks : " << numblocks << std::endl;
    for (int i=0; i < N; i++){
        x[i] = 2.0f;
        y[i] = 3.0f;
    }

    for (int i=0; i < N; i++){
        x_gpu[i] = 2.0f;
        y_gpu[i] = 3.0f;
    }

    // add elements
    add_on_cpu(N, x, y);
    cudaDeviceGetAttribute(&value, cudaDevAttrMultiProcessorCount, dev_id);
    add_on_gpu<<<value*8, 512>>>(N, x_gpu, y_gpu);
    cudaDeviceSynchronize();


    float maxError = 0.0f;
    for (int i=0; i < N; i++)
        maxError = fmax(maxError, fabs(y[i] - 5.0f));
    std::cout << "Max error (cpu) : " << maxError << std::endl;

    for (int i=0; i < N; i++)
        maxError = fmax(maxError, fabs(y_gpu[i] - 5.0f));
    std::cout << "Max error (gpu) : " << maxError << std::endl;
    // free memory
    delete [] x;
    delete [] y;

    cudaFree(x_gpu);
    cudaFree(y_gpu);

    return 0;
}

#include <cstdio>
#include <cuda.h>
#include <iostream>

int main() {

    int nDevices;
    cudaError_t err = cudaGetDeviceCount(&nDevices);
    // expand this program with cudaGetErrorString()
    // cudaGetLastError() and cudaPeekAtLastError()
    // and understand in relation to cudaDeviceSynchronize and asynchrnoize
    // operations
    if (err != cudaSuccess)
        std::cout << " GPU device count failed" << std::endl;
    for(int i = 0; i < nDevices; i++){
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, i);
        std::cout<<" Device number:" << i << "\n";
        std::cout<<" Device name:" << prop.name << "\n";
        std::cout<<" Memory clock rate (KHz):" << prop.memoryClockRate << "\n";
        std::cout<<" Memory Bus width (bits) : " << prop.memoryBusWidth << "\n";
        std::cout<<" Compute capability : " << prop.major << "." << prop.minor << "\n";
        std::cout<<" Is Multi GPU board? : " << prop.isMultiGpuBoard << "\n";
        std::cout<<" Max block per SM : " << prop.maxBlocksPerMultiProcessor << "\n";
        std::cout<<" Max threads per SM : " << prop.maxThreadsPerBlock << "\n";
        std::cout<<" Peak memory bandwidth (GB/s) : " <<
            2.0*prop.clockRate*(prop.memoryBusWidth/8)/1.0e6 << "\n";
    }
}

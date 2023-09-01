#include <iostream>
#include <cublas_v2.h>

int main() {
    cublasStatus_t status;
    cublasHandle_t handle;

    status = cublasCreate(&handle);
    if (status != CUBLAS_STATUS_SUCCESS) {
        std::cerr << "CuBLAS initialization failed." << std::endl;
        return 1;
    }

    float x = 2.0f;
    status = cublasSscal(handle, 1, &x, &x, 1);
    if (status != CUBLAS_STATUS_SUCCESS) {
        std::cerr << "CuBLAS function call failed." << std::endl;
        cublasDestroy(handle); // Clean up before exiting
        return 1;
    }

    std::cout << "Scaled value: " << x << std::endl;

    status = cublasDestroy(handle);
    if (status != CUBLAS_STATUS_SUCCESS) {
        std::cerr << "CuBLAS destruction failed." << std::endl;
        return 1;
    }

    return 0;
}

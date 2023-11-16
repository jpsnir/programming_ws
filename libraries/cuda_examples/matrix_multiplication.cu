#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cstdio>


/* Some important highlights of this example:
 * Tells you some essential steps of the example to figure out the process of
 *    implementation of any cuda algorithm.
 *
 * 1. First thing to figure out is memory allocation of the data.
 *    Sometimes a single mathematical operation need to be performed on the
 *    data. This type is the best example for parallel programming.
 *
 *    Sometimes the data interaction can be parallelized such as matrix
 *    multiplication and other operations. This is also a pattern.
 *
 * 2. Next thing to decide is based on what operation is to be parallelized.
 *    Here in this example each (i,j) element of the output matrix is computed in
 *    parallel.
 *
 * 3. Once it is figured out which operation is to parallelize, we need to find
 *    out how many threads we need - this will also dictate the block size and
 *    grid size, should we use 1D, 2D or 3D grids of threads to compute
 *
 * 4. Figure out the elementary operation for each thread to be processed in the
 *    cuda kernel. This will iterate back to step 2 if a result cannot be found.
 *
 * 5. Implement and test. - can happen while you are thinking each step on
 *    paper.
 *
 */
typedef struct{
    int width;
    int height;
    float *elements;
}Matrix;



#define BLOCK_SIZE 16
__global__ void MatMulKernel(const Matrix, const Matrix, Matrix);


void Matmul(const Matrix A, const Matrix B, Matrix C){
    Matrix d_A;
    d_A.width = A.width;
    d_A.height = A.height;
    size_t size = A.width*A.height*sizeof(float);
    cudaMalloc(&d_A.elements, size); // this part is still confusing.
    cudaMemcpy(d_A.elements, A.elements, size, cudaMemcpyHostToDevice);
    Matrix d_B;
    d_B.width = B.width;
    d_B.height = B.height;
    size = B.width*A.height*sizeof(float);
    cudaMalloc(&d_B.elements, size);
    cudaMemcpy(d_B.elements,B.elements, size,cudaMemcpyHostToDevice);

    //Allocate C
    Matrix d_C;
    d_C.width = C.width;
    d_C.height = C.height;
    size = C.width*C.height*sizeof(float);
    cudaMalloc(&d_C.elements, size);

    //kernel
    // For a block size of 16 in each dimension
    // we will have 256 threads in a single block
    dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE); // no. of threads in each block

    // this defines the size of the block,
    // based on the size of C. The number of rows in
    // A - height(m) x width(n), B - height(n) x width(p) , C - mxp
    // Number of threads for rows or height of C should be M. Since each block
    // has threads of size BLOCK_SIZE,
    // we have grid dimension decided in row by A.height/BLOCK_SIZE
    // Similary, number of threads in col dimension are required to be p,
    // leading to grids in col dimension to be B.width/BLOCK_SIZE.
    //
    // NOTE: whether we assign this to grid dimension x or y is programmer's choice.

    dim3 dimGrid(B.width/dimBlock.x, A.height/dimBlock.y); // no. of blocks in
    // grid
    MatMulKernel<<<dimGrid, dimBlock>>>(d_A, d_B, d_C);

    cudaMemcpy(C.elements, d_C.elements, size, cudaMemcpyDeviceToHost);
    cudaFree(d_A.elements);
    cudaFree(d_B.elements);
    cudaFree(d_C.elements);
}

__global__ void MatMulKernel(Matrix A, Matrix B, Matrix C){
    // Total no. of threads for this computation will be
    float Cvalue = 0;
    // row and column of c matrix
    // Note that we assigned grid dim y to be row dimension
    // and grid dim x to be column dimension
    int row = blockIdx.y*blockDim.y + threadIdx.y;
    int col = blockIdx.x*blockDim.x + threadIdx.x;

    // compute element of c by multiplying a row j from A with col k of B.
    // for each element in row j and col k, get the product and add it
    for (int e=0; e<A.width; ++e){
        Cvalue += A.elements[row*A.width + e] * B.elements[e*B.width + col];
        printf("element %d %d %f",row,col, Cvalue);
    }
    C.elements[row*C.width + col] = Cvalue;
}

int main(){
    int rows = 16;
    int cols = 16;
    Matrix a = {
        .width = rows,
        .height = cols,
        .elements = (float*)malloc(rows*cols*sizeof(float))
    };
    Matrix b = {
        .width = rows,
        .height = cols,
        .elements = (float*)malloc(rows*cols*sizeof(float))
    };
    Matrix c = {
        .width = rows,
        .height = cols,
        .elements = (float*)malloc(rows*cols*sizeof(float))
    };

    for(int row=0; row < a.height ; row++){
        for (int col = 0; col < a.width; col++){
            a.elements[row*a.width + col] = col+1;
            b.elements[row*a.width + col] = 4-col;
            c.elements[row*a.width + col] = 0;
        }
    }
    Matmul(a, b, c);
    std::cout << " Matrix a " << std::endl;
    for(int row=0; row < a.height ; row++){
        for (int col = 0; col < a.width; col++){
            std::cout << a.elements[row*a.width + col] << ",";
        }
        std::cout << std::endl;
    }
    std::cout << " Matrix b " << std::endl;
    for(int row=0; row < a.height ; row++){
        for (int col = 0; col < a.width; col++){
            std::cout << b.elements[row*a.width + col] << ",";
        }
        std::cout << std::endl;
    }
    std::cout << " Matrix c " << std::endl;
    for(int row=0; row < a.height ; row++){
        for (int col = 0; col < a.width; col++){
            std::cout << c.elements[row*a.width + col] << ",";
        }
        std::cout << std::endl;
    }
}

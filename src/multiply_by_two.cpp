#include <mypkg/mypkg.hpp>

#if defined(MYPKG_USE_CUDA)
#include "cuda_utils.hpp"

void multiply_by_two(double * vec_h, int n) {
    cublasHandle_t handle;
    double * vec_d;
    double two = 2;
    CUDACHECK(cudaMalloc(&vec_d, n * sizeof(double)));
    CUBLASCHECK(cublasCreate(&handle));
    CUBLASCHECK(cublasSetVector(n, sizeof(double), vec_h, 1, vec_d, 1));
    CUBLASCHECK(cublasDscal(handle, n, &two, vec_d, 1));
    CUBLASCHECK(cublasGetVector(n, sizeof(double), vec_d, 1, vec_h, 1));
    CUDACHECK(cudaFree(vec_d));
}

#else
void multiply_by_two(double * vec, int n) {
    for (int i = 0; i < n; ++i)
        vec[i] *= 2;
}
#endif
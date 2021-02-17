#ifndef CUDA_UTILS_HPP
#define CUDA_UTILS_HPP

#if defined(MYPKG_USE_CUDA)
#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <iostream>

#define CUDACHECK(ans) { cudaCheck((ans), __FILE__, __LINE__); }
#define CUBLASCHECK(ans) { cublasCheck((ans), __FILE__, __LINE__); }

inline void cudaCheck(cudaError_t code, const char *file, int line)
{
   if (code != cudaSuccess) 
   {
      std::cerr << "CUDA Error: " << cudaGetErrorString(code) << " " << file << " " << line;
      exit(code);
   }
}

inline void cublasCheck(cublasStatus_t code, const char *file, int line)
{
   if (code == CUBLAS_STATUS_SUCCESS)
      return;

   if (code == CUBLAS_STATUS_MAPPING_ERROR)
      std::cerr << "CUBLAS_STATUS_MAPPING_ERROR\n";
   if (code == CUBLAS_STATUS_EXECUTION_FAILED)
      std::cerr << "CUBLAS_STATUS_EXECUTION_FAILED\n";
   if (code == CUBLAS_STATUS_INTERNAL_ERROR)
      std::cerr << "CUBLAS_STATUS_INTERNAL_ERROR\n";
   if (code == CUBLAS_STATUS_NOT_SUPPORTED)
      std::cerr << "CUBLAS_STATUS_NOT_SUPPORTED\n";
   if (code == CUBLAS_STATUS_LICENSE_ERROR)
      std::cerr << "CUBLAS_STATUS_LICENSE_ERROR\n";
   
   exit(code);
}

#endif
#endif
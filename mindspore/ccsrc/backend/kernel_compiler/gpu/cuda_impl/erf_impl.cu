/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */ 

#include "erf_impl.cuh"
template <typename T>
__global__ void ErfKernel(T *input, T *output, size_t count) {
  for (size_t i = blockIdx.x * blockDim.x + threadIdx.x; i < (count); i += blockDim.x * gridDim.x) {
    output[i] = static_cast<T>(erf(static_cast<float>(input[i])));
  }
  return;
}

template <typename T>
void Erf(T *input, T *output, size_t count, cudaStream_t cuda_stream) {
  ErfKernel<<<GET_BLOCKS(count), GET_THREADS, 0, cuda_stream>>>(input, output, count);
  return;
}

template void Erf<float>(float *input, float *output, size_t count, cudaStream_t cuda_stream);
template void Erf<half>(half *input, half *output, size_t count, cudaStream_t cuda_stream);

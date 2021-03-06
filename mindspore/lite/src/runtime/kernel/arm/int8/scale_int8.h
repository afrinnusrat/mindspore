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

#ifndef MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_INT8_SCALE_INT8_H_
#define MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_INT8_SCALE_INT8_H_

#include <vector>
#include "src/lite_kernel.h"
#include "nnacl/scale.h"
#include "nnacl/quantization/quantize.h"

namespace mindspore::kernel {

class ScaleInt8CPUKernel : public LiteKernel {
 public:
  ScaleInt8CPUKernel(OpParameter *parameter, const std::vector<lite::Tensor *> &inputs,
                     const std::vector<lite::Tensor *> &outputs, const lite::InnerContext *ctx,
                     const mindspore::lite::PrimitiveC *primitive)
      : LiteKernel(parameter, inputs, outputs, ctx, primitive) {
    scale_param_ = reinterpret_cast<ScaleParameter *>(op_parameter_);
  }
  ~ScaleInt8CPUKernel() override;

  int Init() override;
  int ReSize() override;
  int Run() override;
  int InitParameter();
  int InitScaleOffset();
  int Scale(int task_id);

 private:
  int8_t *input_ptr_ = nullptr;
  int8_t *scale_ = nullptr;
  int8_t *offset_ = nullptr;
  int8_t *output_ptr_ = nullptr;
  bool has_bias_;
  ScaleParameter *scale_param_;

  int InitQuantArgs();
};
}  // namespace mindspore::kernel

#endif  // MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_INT8_SCALE_INT8_H_

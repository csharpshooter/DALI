// Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DALI_OPERATORS_DECODER_NVJPEG_DECOUPLED_API_FUSED_NVJPEG_DECODER_CPU_CROP_H_
#define DALI_OPERATORS_DECODER_NVJPEG_DECOUPLED_API_FUSED_NVJPEG_DECODER_CPU_CROP_H_

#include <vector>
#include "dali/operators/decoder/nvjpeg/decoupled_api/nvjpeg_decoder_cpu.h"
#include "dali/operators/image/crop/crop_attr.h"

namespace dali {

class nvJPEGDecoderCPUStageCrop : public nvJPEGDecoderCPUStage, protected CropAttr {
 public:
  explicit nvJPEGDecoderCPUStageCrop(const OpSpec& spec)
    : nvJPEGDecoderCPUStage(spec)
    , CropAttr(spec) {
  }

  DISABLE_COPY_MOVE_ASSIGN(nvJPEGDecoderCPUStageCrop);

 protected:
  CropWindowGenerator GetCropWindowGenerator(int data_idx) const override {
    return CropAttr::GetCropWindowGenerator(data_idx);
  }

  void SetupSharedSampleParams(SampleWorkspace &ws) override {
    CropAttr::ProcessArguments(ws);
  }
};

}  // namespace dali

#endif  // DALI_OPERATORS_DECODER_NVJPEG_DECOUPLED_API_FUSED_NVJPEG_DECODER_CPU_CROP_H_

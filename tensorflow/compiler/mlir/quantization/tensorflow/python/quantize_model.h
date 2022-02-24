/* Copyright 2022 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_COMPILER_MLIR_QUANTIZATION_TENSORFLOW_QUANTIZE_MODEL_H_
#define TENSORFLOW_COMPILER_MLIR_QUANTIZATION_TENSORFLOW_QUANTIZE_MODEL_H_

#include <string>
#include <vector>

#include "absl/strings/string_view.h"
#include "tensorflow/core/framework/graph.pb.h"
#include "tensorflow/stream_executor/lib/statusor.h"

namespace mlir {
namespace quant {

// Quantizes the given QAT-enabled model.
stream_executor::port::StatusOr<tensorflow::GraphDef> QuantizeQATModel(
    absl::string_view saved_model_path, absl::string_view exported_names_str,
    absl::string_view tags);

// Quantizes the given model with post-training quantization. This method covers
// the part for the pre-calibration stage.
stream_executor::port::StatusOr<tensorflow::GraphDef>
QuantizePTQModelPreCalibration(absl::string_view saved_model_path,
                               absl::string_view exported_names_str,
                               absl::string_view tags);

// Quantizes the given model with post-training quantization. This method covers
// the part for the post-calibration stage.
stream_executor::port::StatusOr<tensorflow::GraphDef>
QuantizePTQModelPostCalibration(absl::string_view saved_model_path,
                                absl::string_view exported_names_str,
                                absl::string_view tags);
}  // namespace quant
}  // namespace mlir

#endif  // TENSORFLOW_COMPILER_MLIR_QUANTIZATION_TENSORFLOW_QUANTIZE_MODEL_H_

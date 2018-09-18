// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef LAYER_POOLING_H
#define LAYER_POOLING_H

#include "layer.h"
#include <vector>

namespace nvdla {

class Pooling : public Layer
{
public:
    Pooling();

    virtual int load_param(const ParamDict& pd);
    virtual int convert_to_nvdla_layer(std::vector<Layer *> *nvdla_layers);

//    virtual int forward(const Mat& bottom_blob, Mat& top_blob, const Option& opt) const;

    enum { PoolMethod_MAX = 0, PoolMethod_AVE = 1 };

public:
    // param
    int pooling_type;
    int kernel_w;
    int kernel_h;
    int stride_w;
    int stride_h;
    int pad_left;
    int pad_right;
    int pad_top;
    int pad_bottom;
    int global_pooling;
    int pad_mode;// 0=full 1=valid 2=SAME
};

} // namespace ncnn

#endif // LAYER_POOLING_H

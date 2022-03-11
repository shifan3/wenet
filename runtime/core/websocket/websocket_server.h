// Copyright (c) 2020 Mobvoi Inc (Binbin Zhang)
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

#ifndef WEBSOCKET_WEBSOCKET_SERVER_H_
#define WEBSOCKET_WEBSOCKET_SERVER_H_

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>

#include "decoder/torch_asr_decoder.h"
#include "decoder/torch_asr_model.h"
#include "frontend/feature_pipeline.h"
#include "utils/log.h"

namespace wenet {

class WebSocketServer {
 public:
    WebSocketServer(int port,
                                    std::shared_ptr<FeaturePipelineConfig> feature_config,
                                    std::shared_ptr<DecodeOptions> decode_config,
                                    std::shared_ptr<DecodeResource> decode_resource)
            : port_(port),
                feature_config_(std::move(feature_config)),
                decode_config_(std::move(decode_config)),
                decode_resource_(std::move(decode_resource)) {}

    void Start();

 private:
    int port_;
    // The io_context is required for all I/O
    // asio::io_context ioc_{1};
    std::shared_ptr<FeaturePipelineConfig> feature_config_;
    std::shared_ptr<DecodeOptions> decode_config_;
    std::shared_ptr<DecodeResource> decode_resource_;
    WENET_DISALLOW_COPY_AND_ASSIGN(WebSocketServer);
};

}    // namespace wenet

#endif    // WEBSOCKET_WEBSOCKET_SERVER_H_

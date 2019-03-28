// Copyright 2019 The Dawn Authors
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

#include "dawn_wire/WireClient.h"
#include "dawn_wire/client/Client.h"

namespace dawn_wire {

    WireClient::WireClient(CommandSerializer* serializer) : mImpl(new client::Client(serializer)) {
    }

    WireClient::~WireClient() {
        mImpl.reset();
    }

    DawnDevice WireClient::GetDevice() const {
        return mImpl->GetDevice();
    }

    DawnProcTable WireClient::GetProcs() const {
        return client::GetProcs();
    }

    const char* WireClient::HandleCommands(const char* commands, size_t size) {
        return mImpl->HandleCommands(commands, size);
    }

    ReservedTexture WireClient::ReserveTexture(DawnDevice device) {
        return mImpl->ReserveTexture(device);
    }

}  // namespace dawn_wire

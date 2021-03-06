// Copyright 2020 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/execution/local-isolate.h"

#include "src/execution/isolate.h"
#include "src/execution/thread-id.h"
#include "src/handles/handles-inl.h"
#include "src/logging/local-logger.h"

namespace v8 {
namespace internal {

LocalIsolate::LocalIsolate(Isolate* isolate)
    : HiddenLocalFactory(isolate),
      heap_(isolate->heap()),
      isolate_(isolate),
      logger_(new LocalLogger()),
      thread_id_(ThreadId::Current()) {}

LocalIsolate::~LocalIsolate() = default;

int LocalIsolate::GetNextScriptId() { return isolate_->GetNextScriptId(); }

#if V8_SFI_HAS_UNIQUE_ID
int LocalIsolate::GetNextUniqueSharedFunctionInfoId() {
  return isolate_->GetNextUniqueSharedFunctionInfoId();
}
#endif  // V8_SFI_HAS_UNIQUE_ID

bool LocalIsolate::is_collecting_type_profile() {
  // TODO(leszeks): Figure out if it makes sense to check this asynchronously.
  return isolate_->is_collecting_type_profile();
}

}  // namespace internal
}  // namespace v8

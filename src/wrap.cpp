#include <napi.h>

#include "Store.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Store::Init(env, exports);

  return exports;
}

NODE_API_MODULE(phonestore, Init)

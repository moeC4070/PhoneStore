#pragma once

#include <napi.h>
#include <vector>

#include "Phone.h"

class Store : public Napi::ObjectWrap<Store> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Store(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;
  Napi::Value addPhone(const Napi::CallbackInfo &info);
  Napi::Value buyPhone(const Napi::CallbackInfo &info);
  Napi::Value sellPhone(const Napi::CallbackInfo &info);
  Napi::Value fetchPhones(const Napi::CallbackInfo &info);
  std::vector<Phone> phones;
};

#include "Store.h"

Napi::FunctionReference Store::constructor;
//========INITIALIZE THE STORE===============
Napi::Object Store::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func =
      DefineClass(env, "Store",
                  {InstanceMethod("addPhone", &Store::addPhone),

                   InstanceMethod("buyPhone", &Store::buyPhone),

                   InstanceMethod("sellPhone", &Store::sellPhone),

                   InstanceMethod("fetchPhones", &Store::fetchPhones)});

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Store", func);

  return exports;
}

Store::Store(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Store>(info) {}
//==============THE FUNCTIONS TO BE CALLED================
Napi::Value Store::addPhone(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info.Length() < 3 || !info[0].IsString() || !info[1].IsNumber() ||
      !info[2].IsNumber()) {

    Napi::TypeError::New(env, "addPhone(brand, id, stock) expected")
        .ThrowAsJavaScriptException();

    return env.Undefined();
  }

  std::string brand = info[0].As<Napi::String>();

  int id = info[1].As<Napi::Number>().Int32Value();

  int stock = info[2].As<Napi::Number>().Int32Value();

  if (stock < 0) {
    Napi::RangeError::New(env, "stock cannot be negative")
        .ThrowAsJavaScriptException();

    return env.Undefined();
  }

  phones.emplace_back(brand, id, stock);

  return Napi::Boolean::New(env, true);
}

Napi::Value Store::buyPhone(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1 || !info[0].IsNumber()) {

    Napi::TypeError::New(env, "buyPhone(id) expected")
        .ThrowAsJavaScriptException();

    return env.Undefined();
  }

  int id = info[0].As<Napi::Number>().Int32Value();

  for (Phone &phone : phones) {

    if (phone.getId() == id) {
      return Napi::Boolean::New(env, phone.buy());
    }
  }

  return Napi::Boolean::New(env, false);
}

Napi::Value Store::sellPhone(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1 || !info[0].IsNumber()) {

    Napi::TypeError::New(env, "sellPhone(id) expected")
        .ThrowAsJavaScriptException();

    return env.Undefined();
  }

  int id = info[0].As<Napi::Number>().Int32Value();

  for (Phone &phone : phones) {

    if (phone.getId() == id) {
      phone.sell();

      return Napi::Boolean::New(env, true);
    }
  }

  return Napi::Boolean::New(env, false);
}

Napi::Value Store::fetchPhones(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  Napi::Array result = Napi::Array::New(env, phones.size());

  for (size_t i = 0; i < phones.size(); ++i) {

    Napi::Object phone = Napi::Object::New(env);

    phone.Set("id", phones[i].getId());

    phone.Set("brand", phones[i].getBrand());

    phone.Set("stock", phones[i].getStock());

    result.Set(i, phone);
  }

  return result;
}

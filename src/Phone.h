#pragma once

#include <string>

class Phone {
public:
  Phone(const std::string &brand, int id, int stock)
      : brand(brand), id(id), stock(stock) {}

  const std::string &getBrand() const { return brand; }

  int getId() const { return id; }

  int getStock() const { return stock; }

  bool buy() {
    if (stock <= 0) {
      return false;
    }

    --stock;
    return true;
  }

  void sell() { ++stock; }

private:
  std::string brand;
  int id;
  int stock;
};
;

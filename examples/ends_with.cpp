#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string name = "John Doe";
  if (StrUtils::ends_with(name, "Doe")) {
    std::cout << "The name " << name << " ends with Doe." << std::endl;
  }
}
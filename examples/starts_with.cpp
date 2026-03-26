#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string string = "abc123";
  if (StrUtils::starts_with(string, "abc")) {
    std::cout << "The string " << string << " starts with abc." << std::endl;
  }
}
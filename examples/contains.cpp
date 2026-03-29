#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string string = "abc123";
  if (StrUtils::contains(string, "123")) {
    std::cout << "The string " << string << " contains 123." << std::endl;
  }
}
#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string my_string = "abc|123|def|456";
  std::vector<std::string> parts = StrUtils::split(my_string, '|');

  for (const std::string& part : parts) {
    std::cout << part << std::endl;
  }

  std::string joined_string = StrUtils::join(parts, '|');
  std::cout << "Joined string: " << joined_string << std::endl;
}
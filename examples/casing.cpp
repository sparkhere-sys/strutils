#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string string = "HeLlO wOrLd";
  std::string uppercase_string = StrUtils::to_upper(string);
  std::string lowercase_string = StrUtils::to_lower(string);

  std::cout << "Original: " << string << std::endl;
  std::cout << "Uppercase: " << uppercase_string << std::endl;
  std::cout << "Lowercase: " << lowercase_string << std::endl;
}
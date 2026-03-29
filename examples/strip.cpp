#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string string = " wow such whitespace ";
  std::string stripped_string = StrUtils::strip(string);
  std::cout << "Original: " << string << std::endl;
  std::cout << "Stripped: " << stripped_string << std::endl;
}
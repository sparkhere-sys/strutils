#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string string = "abc123";
  if (StrUtils::starts_with(string, "abc")) {
    std::cout << "The string " << string << " starts with abc." << std::endl;
  }
  
  std::string name = "John Doe";
  if (StrUtils::ends_with(name, "Doe")) {
    std::cout << "The name " << name << " ends with Doe." << std::endl;
  }
}
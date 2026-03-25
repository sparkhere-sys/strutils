#include <iostream>
#include <string>
#include "StrUtils.hpp"

int main() {
  std::string my_string = "Hello/World!";
  my_string = StrUtils::replace_all(my_string, "/", ", ");

  std::cout << my_string << std::endl; // Hello, World!
}
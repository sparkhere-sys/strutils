/*
  StrUtils
  STRing UTILitieS
  made with <3 by spark

  This project is licensed under the LGPLv3 License. See LICENSE for more details.
*/

// INCLUDES

#include <string>
#include <vector>

// NAMESPACES

namespace StrUtils {
  inline std::string replace_all(const std::string& str, const std::string& from, const std::string& to) {
    /*
    replaces all occurences of the argument `from` to the argument `to`

    ARGS
      str: the string to perform the replacement on
      from: the string to replace
      to: the string to replace with
    */

    std::string result = str;
    size_t pos = 0; // no regex, screw you

    while ((pos = result.find(from, pos)) != std::string::npos) {
      result.replace(pos, from.length(), to);
      pos += to.length(); // move past the replacement
    }

    return result;
  }

  inline bool starts_with(const std::string& str, const std::string& prefix) {
    /*
    checks if the string `str` starts with the string `prefix`

    ARGS
      str: the string to check
      prefix: the string to check for
    */

    return str.length() >= prefix.length() && str.substr(0, prefix.length()) == prefix;
  }

  inline bool ends_with(const std::string& str, const std::string& suffix) {
    /*
    checks if the string `str` ends with the string `suffix`

    ARGS
      str: the string to check
      suffix: the string to check for
    */

    return str.length() >= suffix.length() && str.substr(str.length() - suffix.length()) == suffix;
  }

  inline std::vector<std::string> split(const std::string& str, char delimiter) {
    /*
    splits a string into a vector of strings based on a delimiter
    
    ARGS
      str: the string to split
      delimiter: the character to split on
    */

    std::vector<std::string> result;
    std::string current;

    for (char c : str) {
      if (c == delimiter) {
        result.push_back(current);
        current.clear();
      } else {
        current += c;
      }
    }

    if (!current.empty()) {
      result.push_back(current);
    }

    return result;
  }
}
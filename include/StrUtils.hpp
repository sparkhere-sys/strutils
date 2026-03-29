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

inline std::string strip(const std::string& str) {
  /*
  removes leading and trailing whitespace from a string

  ARGS
    str: the string to strip
  */

  size_t start = str.find_first_not_of(" \t\n\r\f\v");
  if (start == std::string::npos) {return "";}

  size_t end = str.find_last_not_of(" \t\n\r\f\v");
  return str.substr(start, end - start + 1);
}

inline bool contains(const std::string& str, const std::string& substring) {
  /*
  checks if the string `str` contains the string `substring`

  ARGS
    str: the string to check
    substring: the string to check for
  */

  return str.find(substring) != std::string::npos;
}

inline std::string to_upper(const std::string& str) {
  /*
  converts a string to uppercase

  ARGS
    str: the string to convert
  */
  
  /* NOTE: this and to_lower are kind of useless in my opinion.
     i say this because of std::toupper and std::tolower existing.
     at that point you're just reinventing the wheel. instead of using these functions you could do
     `c = std::toupper(c);` directly in your code, instead of using StrUtils::to_upper and StrUtils::to_lower.
   */

  std::string result = str;
  for (char& c : result) {
    c = std::toupper(c);
  }
  return result;
}

inline std::string to_lower(const std::string& str) {
  /*
  converts a string to lowercase

  ARGS
    str: the string to convert
  */

  // see NOTE in to_upper

  std::string result = str;
  for (char& c : result) {
    c = std::tolower(c);
  }
  return result;
}

inline int count(const std::string& str, const std::string& substring) {
  /*
  counts the number of occurrences of the string `substring` in the string `str`

  ARGS
    str: the string to check
    substring: the string to count
  */

  int result = 0;
  size_t pos = 0;

  if (substring.empty()) {return 0;} // guards against infinite loops

  while ((pos = str.find(substring, pos)) != std::string::npos) {
    ++result;
    pos += substring.length();
  }

  return result;
}

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

  if (from.empty()) {return str;} // guards against infinite loops

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

  /* NOTE: C++20 has std::string::starts_with and std::string::ends_with. this is for
           backwards compatibility with C++17 and earlier.
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

  // see NOTE in starts_with()

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

  if (str.back() == delimiter) {result.push_back("");} // keeps trailing empty strings if the string ends with a delimiter

  return result;
}

inline std::string join(const std::vector<std::string>& strings, char delimiter) {
  /*
  joins a vector of strings into a single string with a delimiter in between

  ARGS
    strings: the vector of strings to join
    delimiter: the character to join with
  */

  std::string result;

  for (size_t i = 0; i < strings.size(); ++i) {
    result += strings[i];
    if (i < strings.size() - 1) {
      result += delimiter;
    }
  }

  return result;
}

}
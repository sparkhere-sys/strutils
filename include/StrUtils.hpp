/*
  StrUtils
  STRing UTILitieS
  made with <3 by spark

  This project is licensed under the LGPLv3 License. See LICENSE for more details.
*/

// INCLUDES

#include <cctype>
#include <string> // would be a disaster if a library named strutils doesn't use strings
#include <string_view>
#include <vector>

// NAMESPACES

namespace strutils {

inline std::string strip(std::string_view str) {
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
  std::string result = str;
  for (char& c : result) {
    c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    // in plain english,
    // c = std::toupper(c);
    // we do this because sometimes char is signed and
    // the value could be negative
  }
  return result;
}

inline std::string to_lower(const std::string& str) {
  std::string result = str;
  for (char& c : result) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    // in plain english,
    // c = std::tolower(c);
    // we do this because sometimes char is signed and
    // the value could be negative
  }
  return result;
}

inline int count(const std::string& str, const std::string& substring) {
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
  return str.length() >= prefix.length() && str.substr(0, prefix.length()) == prefix;
}

inline bool ends_with(const std::string& str, const std::string& suffix) {
  return str.length() >= suffix.length() && str.substr(str.length() - suffix.length()) == suffix;
}

inline std::vector<std::string> split(const std::string& str, char delimiter) {
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

  if (!str.empty() && str.back() == delimiter) {result.push_back("");}
    // keeps trailing empty strings if the string ends with a delimiter

  return result;
}

inline std::string join(const std::vector<std::string>& strings, char delimiter) {
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
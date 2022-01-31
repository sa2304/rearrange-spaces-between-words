#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  pair<vector<string_view>, int> splitWords(string_view text) {
    vector<string_view> words;
    int spaces_count = 0;
    for (int i = 0; i < text.length();) {
      if (isspace(text[i])) { ++spaces_count; ++i; }
      else {
        size_t end_of_word = text.find(' ', i + 1);
        if (string::npos == end_of_word) {
          words.push_back(text.substr(i));
          break;
        } else {
          size_t word_len = end_of_word - i;
          words.push_back(text.substr(i, word_len));
          i += word_len;
        }
      }
    }

    return { words, spaces_count };
  }

 public:
  string reorderSpaces(string text) {
    auto [words, spaces_count] = splitWords(text);
    int separators_count = words.size() - 1;
    int separator_size = (0 < separators_count) ? spaces_count / separators_count : 0;
    int trailing_spaces_count = (0 < separators_count) ? spaces_count % separators_count : spaces_count;

    string result;
    result.reserve(text.length());
    string sep(separator_size, ' ');
    for (int i = 0; i < words.size(); ++i) {
      if (0 < i) {
        result += sep;
      }
      result += words[i];
    }
    if (0 < trailing_spaces_count) {
      result += string(trailing_spaces_count, ' ');
    }

    return result;
  }
};

void TestReorderSpaces() {
  Solution s;
  assert("this   is   a   sentence"s == s.reorderSpaces("  this   is  a sentence "s));
  assert("practice   makes   perfect "s == s.reorderSpaces(" practice   makes   perfect"s));
  assert("hello  "s == s.reorderSpaces("  hello"s));
}

int main() {
  TestReorderSpaces();
  std::cout << "Ok!" << std::endl;
  return 0;
}

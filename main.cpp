#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string reorderSpaces(string text) {
    // FIXME
    return {};
  }
};

void TestReorderSpaces() {
  Solution s;
  assert("this   is   a   sentence"s == s.reorderSpaces("  this   is  a sentence "s));
  assert("practice   makes   perfect "s == s.reorderSpaces(" practice   makes   perfect"s));
//  assert(""s == s.reorderSpaces(""s));
}

int main() {
  TestReorderSpaces();
  std::cout << "Ok!" << std::endl;
  return 0;
}

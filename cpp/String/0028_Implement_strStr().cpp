#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    if (needle.size() > haystack.size()) return -1;
    int next[needle.size()];
    getNext(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i) {
      while (haystack[i] != needle[j] && j > 0) j = next[j - 1];
      if (haystack[i] == needle[j]) j++;
      if (j == needle.size()) return (i - needle.size() + 1);
    }
    return -1;
  }

  void getNext(int *next, const string &s) {
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
      while (s[i] != s[j] && j > 0) j = next[j - 1];
      if (s[i] == s[j]) j++;
      next[i] = j;
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

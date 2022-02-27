#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  string reverseWords(string s) {
    removeExtraSpaces(s);
    reverse(s, 0, s.size() - 1);
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        reverse(s, start, i - 1);
        start = i + 1;
      }
      if (i == (s.size() - 1) && s[i] != ' ') reverse(s, start, i);
    }
    return s;
  }

  void removeExtraSpaces(string &s) {
    int slow = 0, fast = 0;
    while (fast < s.size() && s[fast] == ' ') fast++;
    while (fast < s.size()) {
      if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') fast++;
      else s[slow++] = s[fast++];
    }
    if (s[slow - 1] == ' ') s.resize(slow - 1);
    else s.resize(slow);
  }

  void reverse(string &s, int start, int end) {
    while (end > start) {
      s[start] ^= s[end];
      s[end] ^= s[start];
      s[start] ^= s[end];
      start++;
      end--;
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

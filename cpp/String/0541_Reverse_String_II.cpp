#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      if (i + k <= s.size()) reverse(s, i, i + k - 1);
      else reverse(s, i, s.size() - 1);
    }
    return s;
  }

  void reverse(string &s, int start, int end) {
    while (end > start) {
      s[start] ^= s[end];
      s[end] ^= s[start];
      s[start] ^= s[end];
      end--;
      start++;
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

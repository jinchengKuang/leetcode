#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    return (next[len - 1] != 0 && len % (len - next[len - 1]) == 0);
  }

  void getNext(int *next, const string &s) {
    int j = 0;
    next[0] = j;
    for (int i = 1; i < s.size(); ++i) {
      while (j > 0 && s[i] != s[j]) j = next[j - 1];
      if (s[i] == s[j]) j++;
      next[i] = j;
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

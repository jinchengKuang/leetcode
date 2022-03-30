#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int countSubstrings(string s) {
    int res = 0;
    vector <vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i; j < s.size(); ++j) {
        if (s[i] == s[j]) {
          if (j == i || j - i == 1) {
            res++;
            dp[i][j] = true;
          } else if (dp[i + 1][j - 1]) {
            res++;
            dp[i][j] = true;
          }
        }
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
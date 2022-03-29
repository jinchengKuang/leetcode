#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int numDistinct(string s, string t) {
    vector <vector<size_t>> dp(s.size() + 1, vector<size_t>(t.size() + 1));
    for (int i = 0; i < s.size(); ++i) dp[i][0] = 1;
    for (int j = 1; j < t.size(); ++j) dp[0][j] = 0;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= t.size(); ++j) {
        if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[s.size()][t.size()];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
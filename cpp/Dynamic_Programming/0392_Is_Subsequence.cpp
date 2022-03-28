#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * dp
   * */
  bool isSubsequence(string s, string t) {
    vector <vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= t.size(); ++j) {
        if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = dp[i][j - 1];
      }
    }
    return dp[s.size()][t.size()] == s.size();
  }

  /*
   * two pointers
   * */
  bool isSubsequence2(string s, string t) {
    int p1 = 0, p2 = 0;
    while (p1 < s.size() && p2 < t.size()) {
      if (s[p1] == t[p2]) p1++;
      p2++;
    }
    return p1 == s.size();
  }

};
//leetcode submit region end(Prohibit modification and deletion)
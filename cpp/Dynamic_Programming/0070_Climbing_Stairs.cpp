#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int climbStairs(int n) {
    if (n <= 1) return n;
    int dp[3];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      int sum = dp[1] + dp[2];
      dp[1] = dp[2];
      dp[2] = sum;
    }
    return dp[2];
  }

  int climbStairs2(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= 2; ++j) {
        if (i - j >= 0) {
          dp[i] += dp[i - j];
        }
      }
    }
    return dp[n];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
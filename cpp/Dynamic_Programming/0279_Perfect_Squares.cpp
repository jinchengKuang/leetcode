#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }

  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i * i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (j - i * i >= 0) {
          dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
      }
    }
    return dp[n];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
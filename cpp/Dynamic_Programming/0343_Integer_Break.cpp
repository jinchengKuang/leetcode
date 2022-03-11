#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * dp
   * */
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j < i - 1; ++j) {
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
      }
    }
    return dp[n];
  }

  /*
   * greedy
   * */
  int integerBreak2(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    int result = 1;
    while (n > 4) {
      result *= 3;
      n -= 3;
    }
    result *= n;
    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
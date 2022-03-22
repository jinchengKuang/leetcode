#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * greedy
   * */
  int maxProfit(vector<int>& prices) {
    int res = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
      if (prices[i + 1] > prices[i]) res += prices[i + 1] - prices[i];
    }
    return res;
  }

  /*
   * dp
   * */
  int maxProfit2(vector<int>& prices) {
    vector <vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[prices.size() - 1][1];
  }
};
//leetcode submit region end(Prohibit modification and deletion)

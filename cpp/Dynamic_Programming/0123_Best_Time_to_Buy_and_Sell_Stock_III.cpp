#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 2d
   * */
  int maxProfit(vector<int>& prices) {
    // state: 0 = no action; 1 = first buy; 2 = first sell; 3 = second buy; 4 = second sell
    vector <vector<int>> dp(prices.size(), vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = dp[i][0];
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
      dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[prices.size() - 1][4];
  }

  /*
   * 1d
   * */
  int maxProfit2(vector<int>& prices) {
    // state: 0 = no action; 1 = first buy; 2 = first sell; 3 = second buy; 4 = second sell
    vector<int> dp(5, 0);
    dp[1] = -prices[0];
    dp[3] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[1] = max(dp[1], dp[0] - prices[i]);
      dp[2] = max(dp[2], dp[1] + prices[i]);
      dp[3] = max(dp[3], dp[2] - prices[i]);
      dp[4] = max(dp[4], dp[3] + prices[i]);
    }
    return dp[4];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
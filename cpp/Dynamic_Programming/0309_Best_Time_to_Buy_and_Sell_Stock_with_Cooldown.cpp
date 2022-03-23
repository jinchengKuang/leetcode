#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 2d
   * */
  int maxProfit(vector<int>& prices) {
    // state: 0 = buy; 1 = sell(two days ago, no cooldown); 2 = sell(today, will cooldown next day); 3 = cooldown
    vector <vector<int>> dp(prices.size(), vector<int>(4, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max({dp[i - 1][0], dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]});
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
      dp[i][2] = dp[i - 1][0] + prices[i];
      dp[i][3] = dp[i - 1][2];
    }
    return max({dp[prices.size() - 1][1], dp[prices.size() - 1][2], dp[prices.size() - 1][3]});
  }

/*
 * 1d
 * */
  int maxProfit2(vector<int>& prices) {
    // state: 0 = buy; 1 = sell(two days ago, no cooldown); 2 = sell(today, will cooldown next day); 3 = cooldown
    vector<int> dp(4, 0);
    dp[0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      int temp0 = dp[0];
      int temp2 = dp[2];
      dp[0] = max({dp[0], dp[1] - prices[i], dp[3] - prices[i]});
      dp[1] = max(dp[1], dp[3]);
      dp[2] = temp0 + prices[i];
      dp[3] = temp2;
    }
    return max({dp[1], dp[2], dp[3]});
  }

};
//leetcode submit region end(Prohibit modification and deletion)
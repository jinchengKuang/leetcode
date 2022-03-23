#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * greedy
   * */
  int maxProfit(vector<int>& prices, int fee) {
    int profit = 0;
    int minPrice = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < minPrice) minPrice = prices[i];
      if (prices[i] > minPrice + fee) {
        profit += prices[i] - minPrice - fee;
        minPrice = prices[i] - fee;
      }
    }
    return profit;
  }

  /*
   * dp 2d
   * */
  int maxProfit2(vector<int>& prices, int fee) {
    // state: 0 = buy; 1 = sell;
    vector <vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
  }

  /*
   * dp 1d
   * */
  int maxProfit2(vector<int>& prices, int fee) {
    // state: 0 = buy; 1 = sell;
    vector<int> dp(2, 0);
    dp[0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[0] = max(dp[0], dp[1] - prices[i]);
      dp[1] = max(dp[1], dp[0] + prices[i] - fee);
    }
    return max(dp[0], dp[1]);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 2d
   * */
  int maxProfit(int k, vector<int>& prices) {
    if (prices.size() == 0) return 0;
    vector <vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
    for (int j = 1; j < 2 * k; j += 2) {
      dp[0][j] = -prices[0];
    }
    for (int i = 1; i < prices.size(); ++i) {
      for (int j = 1; j < 2 * k + 1; j += 2) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
        dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
      }
    }
    return dp[prices.size() - 1][2 * k];
  }

/*
 * 1d
 * */
  int maxProfit2(vector<int>& prices) {
    // state: 0 = no action; 1 = first buy; 2 = first sell; 3 = second buy; 4 = second sell
    if (prices.size() == 0) return 0;
    vector<int> dp(2 * k + 1, 0);
    for (int j = 1; j < 2 * k; j += 2) {
      dp[j] = -prices[0];
    }
    for (int i = 1; i < prices.size(); ++i) {
      for (int j = 1; j < 2 * k + 1; j += 2) {
        dp[j] = max(dp[j], dp[j - 1] - prices[i]);
        dp[j + 1] = max(dp[j + 1], dp[j] + prices[i]);
      }
    }
    return dp[2 * k];
  }

};
//leetcode submit region end(Prohibit modification and deletion)
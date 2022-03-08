#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
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
};
//leetcode submit region end(Prohibit modification and deletion)

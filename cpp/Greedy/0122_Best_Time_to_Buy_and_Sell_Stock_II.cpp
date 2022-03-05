#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int res = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
      if (prices[i + 1] > prices[i]) res += prices[i + 1] - prices[i];
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

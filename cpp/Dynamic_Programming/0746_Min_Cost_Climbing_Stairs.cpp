#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int dp0 = cost[0], dp1 = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
      int dpi = min(dp0, dp1) + cost[i];
      dp0 = dp1;
      dp1 = dpi;
    }
    return min(dp0, dp1);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
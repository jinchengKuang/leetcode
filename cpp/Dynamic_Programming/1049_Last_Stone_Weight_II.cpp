#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int i = 0; i < stones.size(); ++i) sum += stones[i];
    int target = sum >> 1;

    vector<int> dp(target + 1, 0);
    for (int i = 0; i < stones.size(); ++i) {
      for (int j = target; j >= stones[i]; --j) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return sum - target - dp[target];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
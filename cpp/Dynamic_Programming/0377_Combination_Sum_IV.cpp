#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[i]]) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    return dp[target];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
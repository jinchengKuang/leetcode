#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum < abs(target)) return 0;
    if ((sum + target) % 2 == 1) return 0;

    int bagSize = (target + sum) / 2;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = bagSize; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[bagSize];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
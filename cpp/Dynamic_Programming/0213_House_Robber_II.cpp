#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);
    return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
  }

  int robRange(vector<int>& nums, int start, int end) {
    vector<int> dp(nums.size(), 0);
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; ++i) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
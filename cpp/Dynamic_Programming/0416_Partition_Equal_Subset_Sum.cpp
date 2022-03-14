#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 1d array
   * */
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum % 2 != 0) return false;
    int target = sum / 2;

    vector<int> dp(target + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[target] == target;
  }

  /*
   * 2d array
   * */
  bool canPartition2(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum % 2 != 0) return false;
    int target = sum / 2;

    vector <vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
    for (int i = 1; i < nums.size() + 1; ++i) {
      for (int j = 0; j < target + 1; ++j) {
        if (j < nums[i]) dp[i][j] = dp[i - 1][j];
        else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
      }
    }
    return dp[nums.size() - 1][target] == target;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
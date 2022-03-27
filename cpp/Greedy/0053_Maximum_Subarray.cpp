#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * greedy
   * */
  int maxSubArray(vector<int>& nums) {
    int res = INT_MIN;
    int subArrSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      subArrSum += nums[i];
      if (subArrSum > res) res = subArrSum;
      if (subArrSum < 0) subArrSum = 0;
    }
    return res;
  }

  /*
   * dp
   * */
  int maxSubArray2(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
//leetcode submit region end(Prohibit modification and deletion)

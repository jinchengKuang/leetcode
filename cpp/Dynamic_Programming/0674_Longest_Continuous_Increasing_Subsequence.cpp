#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * dp
   * */
  int findLengthOfLCIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
    }
    return *max_element(dp.begin(), dp.end());
  }

  /*
   * greedy
   * */
  int findLengthOfLCIS2(vector<int>& nums) {
    int result = 1;
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) count++;
      else count = 1;
      if (count > result) result = count;
    }
    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
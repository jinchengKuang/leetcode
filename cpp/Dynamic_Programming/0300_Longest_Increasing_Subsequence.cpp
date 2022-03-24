#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int result = 1;
    vector<int> dp(nums.size(), 1);
    dp[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
//leetcode submit region end(Prohibit modification and deletion)
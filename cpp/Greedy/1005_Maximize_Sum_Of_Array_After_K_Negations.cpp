#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0 && k > 0) {
        nums[i] *= -1;
        k--;
      }
    }
    if (k % 2 == 1) {
      sort(nums.begin(), nums.end());
      res -= 2 * nums[0];
    }
    for (int j = 1; j < nums.size(); ++j) {
      res += nums[j];
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

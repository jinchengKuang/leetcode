#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
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
};
//leetcode submit region end(Prohibit modification and deletion)

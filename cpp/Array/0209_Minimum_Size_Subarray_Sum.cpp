#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int res = INT_MAX;
    int start = 0;
    int length = 0;
    int sum = 0;
    for (int end = 0; end < nums.size(); ++end) {
      sum += nums[end];
      while (sum >= target) {
        length = end - start + 1;
        res = res < length ? res : length;
        sum -= nums[start++];
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

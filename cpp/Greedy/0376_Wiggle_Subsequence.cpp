#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int res = 1;
    int curDiff = 0, preDiff = 0;
    for (int i = 0; i < nums.size(); ++i) {
      curDiff = nums[i + 1] - nums[i];
      if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
        res++;
        preDiff = curDiff;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

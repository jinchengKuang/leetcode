#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int jump(vector<int>& nums) {
    int count = 0;
    int currDistance = 0, nextDistance = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      nextDistance = max(i + nums[i], nextDistance);
      if (i == currDistance) {
        currDistance = nextDistance;
        count++;
      }
    }
    return count;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

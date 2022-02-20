#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); ++fast) {
      if (val != nums[fast]) nums[slow++] = nums[fast];
    }
    return slow;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
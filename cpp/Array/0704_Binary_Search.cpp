#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] > target) right = mid - 1;
      else if (nums[mid] < target) left = mid + 1;
      else return mid;
    }
    return -1;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
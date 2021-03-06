#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size(); // different
    while (left < right) {
      int mid = left + ((right - left) >> 1);
      if (target > nums[mid]) left = mid + 1;
      else if (target < nums[mid]) right = mid; // different
      else return mid;
    }
    return left;
  }

  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1; // different
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (target > nums[mid]) left = mid + 1;
      else if (target < nums[mid]) right = mid - 1; // different
      else return mid;
    }
    return left;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
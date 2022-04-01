#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
 * Binary search
 * note:
 * 1. nums array is sorted
 * 2. elements are unique
 * 3. difference between [left, right] and [left, right)
 * */

  // [left, right]
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // different, right is included
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] > target) right = mid - 1; // different
      else if (nums[mid] < target) left = mid + 1;
      else return mid;
    }
    return -1;
  }

  // [left, right)
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size(); // different, right is not included
    while (right > left) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] > target) right = mid; // different
      else if (nums[mid] < target) left = mid + 1;
      else return mid;
    }
    return -1;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * binary search
   * [5, 7, 7, 8, 8, 10]
   *  |left          |right
   * find left bound and right bound separately
   * */
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int size = nums.size() - 1;
    int left, right;

    // find the left bound
    left = 0;
    right = size;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (target > nums[mid]) left = mid + 1;
      else right = mid - 1; // shrink right bound
    }
    if (left <= size && nums[left] == target) res.emplace_back(left); // check left over size
    else res.emplace_back(-1);

    // find the right bound
    left = 0;
    right = size;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (target < nums[mid]) right = mid - 1;
      else left = mid + 1; // shrink left bound
    }
    if (right >= 0 && nums[right] == target) res.emplace_back(right); // check right over size
    else res.emplace_back(-1);

    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
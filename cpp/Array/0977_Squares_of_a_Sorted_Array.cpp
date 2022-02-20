#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
//    vector<int> res(nums.size(), 0);
//    int idx = nums.size() - 1;
//    for (int left = 0, right = idx; left <= right; --idx) {
//      if (nums[left] * nums[left] > nums[right] * nums[right]) {
//        res[idx] = nums[left] * nums[left];
//        left++;
//      } else {
//        res[idx] = nums[right] * nums[right];
//        right--;
//      }
//    }
//    return res;

    vector<int> res(nums.size(), 0);
    int idx = nums.size() - 1;
    int left = 0;
    int right = idx;
    while (left <= right) {
      if (nums[left] * nums[left] > nums[right] * nums[right]) {
        res[idx--] = nums[left] * nums[left];
        left++;
      } else {
        res[idx--] = nums[right] * nums[right];
        right--;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

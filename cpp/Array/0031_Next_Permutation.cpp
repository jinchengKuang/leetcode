#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * two pointers
   * init:
   * [1,3,5,4,2]
   *          |right
   *        |left
   * find the tipping point
   * [1,3,5,4,2]
   *      |right
   *    |left
   * find the element that is just greater than left
   * [1,3,5,4,2]
   *        |right
   *    |left
   * */
  void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return;
    int left = size - 2, right = size - 1;
    // find the tipping point
    while (left > 0 && nums[left] >= nums[right]) {
      left--;
      right--;
    }
    // find the element that is just greater than left
    right = size - 1;
    while (right > left && nums[left] >= nums[right]) {
      right--;
    }
    // exchange left and right, then reverse the end part
    if (left < right) {
      nums[left] ^= nums[right];
      nums[right] ^= nums[left];
      nums[left] ^= nums[right];
      sort(nums.begin() + left + 1, nums.end());
    } else {
      sort(nums.begin(), nums.end());
    }
    return;
  }

  void nextPermutation(vector<int>& nums) {
    /*
     * case 1: [1, 2, 3, 4, 5] ascending
     *       ->[1, 2, 3, 5, 4] swap last two
     * case 2: [5, 4, 3, 2, 1] descending
     *       ->[1, 2, 3, 4, 5] reverse
     * case 3: [1, 3, 5, 4, 2] descending at end part
     *       ->[1, 4, 5, 3, 2] find the element before descending, exchange it with the element that is greater at the end part
     *       ->[1, 4, 2, 3, 5] reverse the end part
     * */
    int size = nums.size();
    if (size == 1) return;
    // search from end to begin, find the index that is the beginning of descending
    int index = size - 1;
    while (index >= 1 && nums[index] <= nums[index - 1]) {
      index--;
    }
    // case 1: [1, 2, 3, 4, 5]
    if (index == size - 1) {
      exchange(nums, index - 1, index);
      return;
    }
    // case 2: [5, 4, 3, 2, 1]
    if (index == 0) {
      reverse(nums.begin(), nums.end());
      return;
    }
    // case 3: [1, 3,       5,     4,           2]
    //             |index-1 |index |swapIndex-1 |swapIndex
    // swap [index - 1] and [swapIndex]
    int swapIndex = index;
    while (swapIndex < size && nums[index - 1] < nums[swapIndex]) {
      swapIndex++;
    }
    exchange(nums, index - 1, swapIndex - 1);
    //    [1,3,5,4,2]
    // -> [1,4,5,3,2]
    // -> [1,4,2,3,5]
    reverse(nums.begin() + index, nums.end());
    return;
  }

  void exchange(vector<int>& nums, int i, int j) {
    // nums element are greater than 0
    nums[i] ^= nums[j];
    nums[j] ^= nums[i];
    nums[i] ^= nums[j];
    return;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
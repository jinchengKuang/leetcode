#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * two pointers
   * [1,8,6,2,5,4,8,3,7]
   *  |left           |right
   *  whoever the height is smaller, then move it
   * */
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int res = 0;
    while (left < right) {
      res = max(min(height[left], height[right]) * (right - left), res);
      if (height[left] < height[right]) ++left;
      else --right;
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
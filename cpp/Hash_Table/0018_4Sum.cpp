#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 1st solution two pointers
   * */
  vector <vector<int>> fourSum(vector<int> &nums, int target) {
    vector <vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int left = j + 1, right = nums.size() - 1;

        while (right > left) {
          if (nums[i] + nums[j] > target - nums[left] - nums[right]) right--;
          else if (nums[i] + nums[j] < target - nums[left] - nums[right]) left++;
          else {
            res.emplace_back(vector < int > {nums[i], nums[j], nums[left], nums[right]});
            while (right > left && nums[right] == nums[right - 1]) right--;
            while (right > left && nums[left] == nums[left + 1]) left++;
            right--;
            left++;
          }
        }
      }
    }

    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

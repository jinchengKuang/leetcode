#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(target - nums[i]) != map.end()) return {i, map[target - nums[i]]};
      map[nums[i]] = i;
    }
    return {};
  }
};
//leetcode submit region end(Prohibit modification and deletion)
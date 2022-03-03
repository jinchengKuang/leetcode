
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> path;
  vector <vector<int>> res;

  void backtracking(vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
      if (!used[i]) {
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
      }
    }
  }

public:
  vector <vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <vector>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> path;
  vector <vector<int>> res;

  void backtracking(vector<int>& nums, int start) {
    res.push_back(path);
    unordered_set<int> set;
    for (int i = start; i < nums.size(); ++i) {
      if (set.find(nums[i]) != set.end()) continue;
      set.insert(nums[i]);
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

public:
  vector <vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    backtracking(nums, 0);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

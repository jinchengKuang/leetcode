#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> path;
  vector <vector<int>> res;

  void backtracking(vector<int>& nums, int start) {
    res.push_back(path);
    for (int i = start; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

public:
  vector <vector<int>> subsets(vector<int>& nums) {
    backtracking(nums, 0);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> path;
  vector <vector<int>> res;

  void backtracking(vector<int>& candidates, int target, int sum, int start) {
    if (sum == target) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < candidates.size() && sum + candidates[i] <= target; ++i) {
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracking(candidates, target, sum, i);
      sum -= candidates[i];
      path.pop_back();
    }
  }

public:
  vector <vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

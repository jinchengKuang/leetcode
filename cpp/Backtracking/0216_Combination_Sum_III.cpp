#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> path;
  vector <vector<int>> res;

  void backtracking(int k, int targetSum, int sum, int start) {
    if (path.size() == k) {
      if (sum == targetSum) res.push_back(path);
      return;
    }
    for (int i = start; i <= 9 - (k - path.size()) + 1; ++i) {
      sum += i;
      path.push_back(i);
      backtracking(k, targetSum, sum, i + 1);
      sum -= i;
      path.pop_back();
    }
  }

public:
  vector <vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 0, 1);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

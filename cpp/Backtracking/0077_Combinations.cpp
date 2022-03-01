#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> path;
  vector <vector<int>> res;

  void backtracking(int n, int k, int start) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < k; ++i) {
      path.push_back(i);
      backtracking(n, k, i + 1);
      path.pop_back();
    }
  }

public:
  vector <vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

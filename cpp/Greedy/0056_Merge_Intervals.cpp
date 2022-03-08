#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector <vector<int>> merge(vector <vector<int>>& intervals) {
    auto cmp = [](const vector<int>& i1, const vector<int>& i2) {
      return i1[0] < i2[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);
    vector <vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= res.back()[1]) res.back()[1] = max(intervals[i][1], res.back()[1]);
      else res.push_back(intervals[i]);
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

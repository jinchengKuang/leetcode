#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int eraseOverlapIntervals(vector <vector<int>>& intervals) {
    int count = 1;
    auto cmp = [](const vector<int>& i1, vector<int>& i2) {
      return i1[1] < i2[1];
    };
    sort(intervals.begin(), intervals.end(), cmp);
    int end = intervals[0][1];
    for (int i = 0; i < intervals.size(); ++i) {
      int start = intervals[i][0];
      if (start >= end) {
        count++;
        end = intervals[i][1];
      }
    }
    return intervals.size() - count;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

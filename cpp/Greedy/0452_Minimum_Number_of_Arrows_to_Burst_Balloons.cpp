#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 1st solution sort by start
   * */
  int findMinArrowShots(vector <vector<int>>& points) {
    if (points.size() == 0) return 0;
    auto cmp = [](const vector<int>& p1, const vector<int>& p2) {
      return p1[0] < p2[0];
    };
    sort(points.begin(), points.end(), cmp);
    int res = 1;
    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] > points[i - 1][1]) res++;
      else points[i][1] = min(points[i - 1][1], points[i][1]);
    }
    return res;
  }

  /*
   * 2nd solution sort by end
   * */
  int findMinArrowShots(vector <vector<int>>& points) {
    if (points.size() == 0) return 0;
    auto cmp = [](const vector<int>& p1, const vector<int>& p2) {
      return p1[1] < p2[1];
    };
    sort(points.begin(), points.end(), cmp);
    int res = 1;
    int end = points[0][1];
    for (int i = 1; i < points.size(); i++) {
      int start = points[i][0];
      if (start > end) {
        res++;
        end = points[i][1];
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
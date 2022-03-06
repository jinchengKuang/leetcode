#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector <vector<int>> reconstructQueue(vector <vector<int>>& people) {
    auto cmp = [](const vector<int>& p1, const vector<int>& p2) {
      if (p1[0] == p2[0]) return p1[1] < p2[1];
      return p1[0] > p2[0];
    };
    sort(people.begin(), people.end(), cmp);
    vector <vector<int>> res;
    for (int i = 0; i < people.size(); ++i) {
      res.insert(res.begin() + people[i][1], people[i]);
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

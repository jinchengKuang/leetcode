#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int index = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (index < g.size() && g[index] <= s[i]) index++;
    }
    return index;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
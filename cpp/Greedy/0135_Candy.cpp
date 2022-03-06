#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int candy(vector<int>& ratings) {
    vector<int> candyVec(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
    }
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
    }
    int res = 0;
    for (int i = 0; i < candyVec.size(); ++i) res += candyVec[i];
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int i = 0; i < bills.size(); ++i) {
      if (bills[i] == 5) five++;
      if (bills[i] == 10) {
        if (five >= 1) {
          five--;
          ten++;
        } else return false;
      }
      if (bills[i] == 20) {
        if (ten >= 1 && five >= 1) {
          five--;
          ten--;
        } else if (five >= 3) {
          five -= 3;
        } else return false;
      }
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

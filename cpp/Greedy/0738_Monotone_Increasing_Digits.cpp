#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    string strN = to_string(n);
    int flag = strN.size();
    for (int i = strN.size() - 1; i > 0; --i) {
      if (strN[i - 1] > strN[i]) {
        flag = i;
        strN[i - 1]--;
      }
    }
    for (int i = flag; i < strN.size(); ++i) {
      strN[i] = '9';
    }
    return stoi(strN);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

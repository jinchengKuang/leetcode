#include <string>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 1st solution use stack
   * */
  string removeDuplicates(string s) {
    stack<char> stk;
    for (char c: s) {
      if (stk.empty() || c != stk.top()) stk.push(c);
      else stk.pop();
    }
    string res = "";
    while (!stk.empty()) {
      res += stk.top();
      stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }

  /*
   * 2nd solution only string
   * */
  string removeDuplicates2(string s) {
    string res = "";
    for (char c: s) {
      if (res.empty() || c != res.back()) res.push_back(c);
      else res.pop_back();
    }
    return res;
  }

};
//leetcode submit region end(Prohibit modification and deletion)

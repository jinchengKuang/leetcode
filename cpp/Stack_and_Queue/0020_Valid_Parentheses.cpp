#include <string>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  bool isValid(string s) {
    if (s.size() % 2 != 0) return false;
    stack<char> stk;
    for (char c: s) {
      if (c == '(') stk.push(')');
      else if (c == '[') stk.push(']');
      else if (c == '{') stk.push('}');
      else if (stk.empty() || stk.top() != c) return false;
      else stk.pop();
    }
    return stk.empty();
  }
};
//leetcode submit region end(Prohibit modification and deletion)

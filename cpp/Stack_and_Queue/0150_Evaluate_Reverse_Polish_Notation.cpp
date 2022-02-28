#include <vector>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int evalRPN(vector <string> &tokens) {
    stack<int> stk;
    for (int i = 0; i < tokens.size(); ++i) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
        int num1 = stk.top();
        stk.pop();
        int num2 = stk.top();
        stk.pop();
        if (tokens[i] == "+") stk.push(num2 + num1);
        if (tokens[i] == "-") stk.push(num2 - num1);
        if (tokens[i] == "*") stk.push(num2 * num1);
        if (tokens[i] == "/") stk.push(num2 / num1);
      } else stk.push(stoi(tokens[i]));
    }
    return stk.top();
  }
};
//leetcode submit region end(Prohibit modification and deletion)

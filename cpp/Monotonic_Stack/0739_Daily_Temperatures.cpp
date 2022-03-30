#include <vector>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < temperatures.size(); ++i) {
      if (temperatures[i] <= temperatures[st.top()]) st.push(i);
      else {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
          res[st.top()] = i - st.top();
          st.pop();
        }
        st.push(i);
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
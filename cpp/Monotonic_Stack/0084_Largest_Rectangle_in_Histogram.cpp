#include <vector>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    stack<int> st;
    st.push(0);

    int res = 0;
    for (int i = 1; i < heights.size(); ++i) {
      while (!st.empty() && heights[i] < heights[st.top()]) {
        int mid = st.top();
        st.pop();
        int h = heights[mid];
        int w = i - st.top() - 1;
        res = max(res, h * w);
      }
      st.push(i);
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    st.push(0);

    vector<int> res(nums.size(), -1);
    for (int i = 0; i < nums.size() * 2; ++i) {
      while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
        res[st.top()] = nums[i % nums.size()];
        st.pop();
      }
      st.push(i % nums.size());
    }

    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
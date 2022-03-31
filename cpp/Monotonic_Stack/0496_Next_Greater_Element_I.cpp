#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    st.push(0);

    unordered_map<int, int> unorderedMap;
    for (int i = 0; i < nums1.size(); ++i) {
      unorderedMap[nums1[i]] = i;
    }

    vector<int> res(nums1.size(), -1);
    for (int i = 1; i < nums2.size(); ++i) {
      while (!st.empty() && nums2[i] > nums2[st.top()]) {
        if (unorderedMap.find(nums2[st.top()]) != unorderedMap.end()) {
          int idx = unorderedMap[nums2[st.top()]];
          res[idx] = nums2[i];
        }
        st.pop();
      }
      st.push(i);
    }

    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
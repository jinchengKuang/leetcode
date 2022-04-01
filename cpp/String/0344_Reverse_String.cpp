#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 1st solution recursion
   * */
  void reverseString(vector<char>& s) {
    traversal(s, 0, s.size() - 1);
  }

  // recursion 3 steps:
  // 1. parameters and  return value
  // 2. termination condition
  // 3. main logic for each recursion

  void traversal(vector<char>& s, int left, int right) {
    if (right <= left) return;
    // more efficient way to swap(s[left++], s[right--]);
    s[left] ^= s[right];
    s[right] ^= s[left];
    s[left] ^= s[right];
    left++;
    right--;

    traversal(s, left, right);
  }

  /*
   * 2nd solution two pointers
   * */
  void reverseString2(vector<char>& s) {
    for (int left = 0, right = s.size() - 1; left < s.size() >> 1; ++left, --right) {
      // more efficient way to swap(s[left], s[right]);
      s[left] ^= s[right];
      s[right] ^= s[left];
      s[left] ^= s[right];
    }
  }

};
//leetcode submit region end(Prohibit modification and deletion)

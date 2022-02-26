#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 1st solution recursion
   * */
  void reverseString(vector<char> &s) {
    traversal(s, 0, s.size() - 1);
  }

  void traversal(vector<char> &s, int left, int right) {
    if (right <= left) return;
    swap(s[left++], s[right--]);
    traversal(s, left, right);
  }

  /*
   * 2nd solution two pointers
   * */
  void reverseString2(vector<char> &s) {
    for (int left = 0, right = s.size() - 1; left < s.size() / 2; ++left, --right) {
//      swap(s[left], s[right]);
      s[left] ^= s[right];
      s[right] ^= s[left];
      s[left] ^= s[right];
    }
  }

};
//leetcode submit region end(Prohibit modification and deletion)

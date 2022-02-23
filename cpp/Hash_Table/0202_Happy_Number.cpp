#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 1st solution hash
   * */
  bool isHappy(int n) {
    unordered_set<int> set;
    int num = getNext(n);
    while (num > 1) {
      if (set.find(num) != set.end()) return false;
      set.insert(num);
      num = getNext(num);
    }
    return true;
  }

  int getNext(int x) {
    int res = 0;
    while (x) {
      res += (x % 10) * (x % 10);
      x /= 10;
    }
    return res;
  }

  /*
   * 2nd solution two pointers
   * */
  bool isHappy2(int n) {
    int slow = n, fast = getNext(n);
    while (slow != fast) {
      slow = getNext(slow);
      fast = getNext(getNext(fast));
      if (fast == 1) return true;
    }
    return fast == 1;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * binary search
   * */
  bool isPerfectSquare(int num) {
    if (num == 1 || num == 4) return true;
    long long left = 0, right = num / 2;
    while (left < right) {
      long long mid = left + ((right - left) >> 1);
      if (num < mid * mid) right = mid;
      else if (num > mid * mid) left = mid + 1;
      else return true;
    }
    return false;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
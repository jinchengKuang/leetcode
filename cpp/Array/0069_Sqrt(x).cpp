using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * binary search
   * searching an array [1, ..., x / 2]
   * */
  int mySqrt(int x) {
    if (x <= 1) return x;
    // long long - because test cases
    long long left = 1, right = x / 2;
    long long mid, square;
    while (left < right) {
      mid = left + ((right - left) >> 1);
      square = mid * mid;
      if (x < square) right = mid;
      else if (x > square) left = mid + 1;
      else return mid;
    }
    return (left * left > x) ? left - 1 : left;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
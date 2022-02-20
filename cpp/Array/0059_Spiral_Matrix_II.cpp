#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector <vector<int>> generateMatrix(int n) {
    vector <vector<int>> res(n, vector<int>(n, 0));
    int upperBound = 0, lowerBound = n - 1, leftBound = 0, rightBound = n - 1;
    int num = 1;
    while (num <= n * n) {
      if (upperBound <= lowerBound) {
        for (int i = leftBound; i <= rightBound; ++i) {
          res[upperBound][i] = num++;
        }
        upperBound++;
      }
      if (leftBound <= rightBound) {
        for (int i = upperBound; i <= lowerBound; ++i) {
          res[i][rightBound] = num++;
        }
        rightBound--;
      }
      if (upperBound <= lowerBound) {
        for (int i = rightBound; i >= leftBound; --i) {
          res[lowerBound][i] = num++;
        }
        lowerBound--;
      }
      if (leftBound <= rightBound) {
        for (int i = lowerBound; i >= upperBound; --i) {
          res[i][leftBound] = num++;
        }
        leftBound++;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
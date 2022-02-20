#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> spiralOrder(vector <vector<int>> &matrix) {
    vector<int> res;
    int row = matrix.size();
    int column = matrix[0].size();
    int upperBound = 0, lowerBound = row - 1, leftBound = 0, rightBound = column - 1;
    while (res.size() < row * column) {
      if (upperBound <= lowerBound) {
        for (int i = leftBound; i <= rightBound; ++i) {
          res.emplace_back(matrix[upperBound][i]);
        }
        upperBound++;
      }
      if (leftBound <= rightBound) {
        for (int i = upperBound; i <= lowerBound; ++i) {
          res.emplace_back(matrix[i][rightBound]);
        }
        rightBound--;
      }
      if (upperBound <= lowerBound) {
        for (int i = rightBound; i >= leftBound; --i) {
          res.emplace_back(matrix[lowerBound][i]);
        }
        lowerBound--;
      }
      if (leftBound <= rightBound) {
        for (int i = lowerBound; i >= upperBound; --i) {
          res.emplace_back(matrix[i][leftBound]);
        }
        leftBound++;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
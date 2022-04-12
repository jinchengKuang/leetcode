#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  void gameOfLife(vector <vector<int>>& board) {
    // note: don't count the node itself
    int idx[8][2] = {{-1, -1},
                     {-1, 0},
                     {-1, 1},
                     {0,  -1},
                     {0,  1},
                     {1,  -1},
                     {1,  0},
                     {1,  1}};
    int m = board.size();
    int n = board[0].size();
    vector <vector<int>> result(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int val = 0;
        for (int k = 0; k < 8; ++k) {
          // val = how many live neighbors
          val += getVal(board, i + idx[k][0], j + idx[k][1]);
        }
        if (board[i][j] == 1) {
          if (val < 2) result[i][j] = 0;
          else if (val <= 3) result[i][j] = 1;
          else result[i][j] = 0;
        } else {
          result[i][j] = val == 3 ? 1 : 0;
        }
      }
    }
    // copy back to original board
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        board[i][j] = result[i][j];
      }
    }
  }

  int getVal(vector <vector<int>> board, int x, int y) {
    return (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) ? 0 : board[x][y];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
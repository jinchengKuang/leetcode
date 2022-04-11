#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector <vector<int>> shiftGrid(vector <vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector <vector<int>> result(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // new i = (i + (j + k) / n) % m
        //   => original at i row, j col
        //   => move down how many rows? at new row = (j + k) / n
        //   => if new row > m? new row & m
        //   => example: i = 1, j = 2, n = 3, k =7
        //   => moves k=7 steps, so the new location is j+k=9 away from the first location
        //   => so where is the new location? (j+k)/n=3 rows down to row i
        //   => so new row i= i+(j+k)/n
        //   => but if move away from the m rows?
        //   => so mod m, so new i = (i + (j + k) / n) % m
        // new j = (j + k) % n
        //   => original at i row, j col
        //   => move right how many cols? at new col = (j + k) % n
        //   => example: j = 1, n = 3, k = 7
        //   => every 3 moves will be back to original, so k=7 steps is equal to 7-3-3 = 1 steps
        //   => so move 1 right, new j = j + (k % n)
        //   => but if move away from the n cols?
        //   => so mod n, so new j = (j + (k % n)) % n = j % n + (k % n)) % n % n = j % n + k % n = (j + k) % n
        result[(i + (j + k) / n) % m][(j + k) % n] = grid[i][j];
      }
    }

    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
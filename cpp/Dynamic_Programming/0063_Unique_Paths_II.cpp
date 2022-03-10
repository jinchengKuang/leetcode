#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 2d vector
   * */
  int uniquePathsWithObstacles(vector <vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector <vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) dp[i][0] = 1;
    for (int i = 0; i < n && obstacleGrid[0][i] == 0; ++i) dp[0][i] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) continue;
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }

  /*
   * 1d vector
   * */
  int uniquePathsWithObstacles2(vector <vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n && obstacleGrid[0][i] == 0; ++i) dp[i] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) dp[j] = 0;
        else if (j > 0) dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
  }

  /*
   * 1d array
   * */
  int uniquePathsWithObstacles(vector <vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[n];
    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[0][i] == 1) {
        for (int j = i; j < n; ++j) dp[j] = 0;
        break;
      } else dp[i] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) dp[j] = 0;
        else if (j > 0) dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
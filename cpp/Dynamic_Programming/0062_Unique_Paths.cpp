using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * 2D array
   * */
  int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int i = 0; i < n; ++i) dp[0][i] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }

  /*
   * 1D array
   * */
  int uniquePaths2(int m, int n) {
    int dp[n];
    for (int i = 0; i < n; ++i) dp[i] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
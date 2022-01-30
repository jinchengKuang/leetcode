#include <vector>
#include <queue>
#include <numeric>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
  /*
   * 1st solution BFS
   * */
  vector<double> averageOfLevels1(TreeNode *root) {
    if (root == nullptr) return {};
    vector<double> res;
    queue < TreeNode * > q;
    q.emplace(root);
    while (!q.empty()) {
      int size = q.size();
      double sum = 0;
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        sum += cur->val;
        if (cur->left) q.emplace(cur->left);
        if (cur->right) q.emplace(cur->right);
      }
      res.emplace_back(sum / size);
    }
    return res;
  }

  /*
 * 2nd solution DFS
 * */
  vector<double> averageOfLevels2(TreeNode *root) {
    if (root == nullptr) return {};
    vector<int> counts;
    vector<double> res;
    dfs(root, res, counts);
    for (int i = 0; i < res.size(); ++i) {
      res[i] /= counts[i];
    }
    return res;
  }

  void dfs(TreeNode *node, vector<double> &res, vector<int> &counts, int level = 0) {
    if (node == nullptr) return;
    if (level >= res.size()) {
      res.emplace_back(node->val * 1.0);
      counts.emplace_back(1);
    } else {
      res[level] += node->val;
      counts[level] += 1;
    }
    dfs(node->left, res, counts, level + 1);
    dfs(node->right, res, counts, level + 1);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
#include <stack>
#include <vector>
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
   * 1st solution recursive
   * */
  vector <vector<int>> res;
  vector<int> path;

  vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (!root) return res;
    path.emplace_back(root->val);
    traversal(root, targetSum - root->val);
    return res;
  }

  void traversal(TreeNode *node, int rest) {
    if (!node->left && !node->right) {
      if (rest == 0) res.emplace_back(path);
      return;
    }
    if (node->left) {
      path.emplace_back(node->left->val);
      rest -= node->left->val;
      traversal(node->left, rest);
      rest += node->left->val;
      path.pop_back();
    }
    if (node->right) {
      path.emplace_back(node->right->val);
      rest -= node->right->val;
      traversal(node->right, rest);
      rest += node->right->val;
      path.pop_back();
    }
    return;
  }

  /*
   * 2nd solution recursive
   * */
  vector <vector<int>> pathSum2(TreeNode *root, int targetSum) {
    if (!root) return {};
    vector <vector<int>> res;
    traversal2(root, targetSum, {}, res);
    return res;
  }

  void traversal2(TreeNode *node, int targetSum, vector<int> path, vector <vector<int>> &res) {
    if (!node) return;
    if (!node->left && !node->right && node->val == targetSum) {
      path.emplace_back(node->val);
      res.emplace_back(path);
      return;
    }
    path.emplace_back(node->val);
    if (node->left) traversal2(node->left, targetSum - node->val, path, res);
    if (node->right) traversal2(node->right, targetSum - node->val, path, res);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
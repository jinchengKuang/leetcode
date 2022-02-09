#include <stack>

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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right && targetSum == root->val) return true;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
  }

  /*
   * 2nd solution iterative
   * */
  bool hasPathSum2(TreeNode *root, int targetSum) {
    if (!root) return false;
    stack <pair<TreeNode *, int>> stk;
    stk.emplace(pair<TreeNode *, int>(root, root->val));
    while (!stk.empty()) {
      pair < TreeNode * , int > node = stk.top();
      stk.pop();
      if (!node.first->left && !node.first->right && node.second == targetSum) return true;
      if (node.first->right)
        stk.emplace(pair<TreeNode *, int>(node.first->right, node.second + node.first->right->val));
      if (node.first->left) stk.emplace(pair<TreeNode *, int>(node.first->left, node.second + node.first->left->val));
    }
    return false;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
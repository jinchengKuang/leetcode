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
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root) return 0;
    int midValue = 0;
    if (root->left && !root->left->left && !root->left->right) midValue = root->left->val;
    return midValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }

  /*
   * 2nd solution iterative
   * */
  int sumOfLeftLeaves2(TreeNode *root) {
    if (!root) return 0;
    int sum = 0;
    stack < TreeNode * > stk;
    stk.emplace(root);
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      if (node->left && !node->left->left && !node->left->right) sum += node->left->val;
      if (node->right) stk.emplace(node->right);
      if (node->left) stk.emplace(node->left);
    }
    return sum;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
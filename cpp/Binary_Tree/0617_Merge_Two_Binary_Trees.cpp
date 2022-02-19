#include <queue>

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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    root1->val += root2->val;
    mergeTrees(root1->left, root2->left);
    mergeTrees(root2->right, root2->right);
    return root1;
  }

  /*
   * 2nd solution iterative level order
   * */
  TreeNode *mergeTrees2(TreeNode *root1, TreeNode *root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    queue < TreeNode * > q;
    q.emplace(root1);
    q.emplace(root2);
    while (!q.empty()) {
      TreeNode *node1 = q.front();
      q.pop();
      TreeNode *node2 = q.front();
      q.pop();
      node1->val += node2->val;
      if (node1->left && node2->left) {
        q.emplace(node1->left);
        q.emplace(node2->left);
      }
      if (!node1->left && node2->left) node1->left = node2->left;
      if (node1->right && node2->right) {
        q.emplace(node1->right);
        q.emplace(node2->right);
      }
      if (!node1->right && node2->right) node1->right = node2->right;
    }
    return root1;
  }

};
//leetcode submit region end(Prohibit modification and deletion)
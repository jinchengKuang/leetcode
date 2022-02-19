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
  int countNodes(TreeNode *root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }

  /*
   * 2nd solution iterative
   * */
  int countNodes2(TreeNode *root) {
    if (!root) return 0;
    queue < TreeNode * > q;
    q.emplace(root);
    int count = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        count++;
        TreeNode *node = q.front();
        q.pop();
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
      }
    }
    return count;
  }

  /*
   * 3rd solution based on complete binary tree
   * */
  int countNodes3(TreeNode *root) {
    if (!root) return 0;
    int leftHeight = 0, rightHeight = 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    while (left) {
      left = left->left;
      leftHeight++;
    }
    while (right) {
      right = right->right;
      rightHeight++;
    }
    if (leftHeight == rightHeight) return (2 << leftHeight) - 1;
    else return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
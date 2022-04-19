#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
   * inorder of BST is ascending
   * so if it is not ascending, then it is a mistake
   * record the mistakes, then swap them
   * */
  void recoverTree(TreeNode* root) {
    inorder(root);
    swap(first->val, second->val);
  }

  TreeNode* pre = new TreeNode(INT_MIN);
  TreeNode* first, * second;

  void inorder(TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);

    if (first == nullptr && pre->val > node->val) first = pre;
    if (first != nullptr && pre->val > node->val) second = node;
    pre = node;

    inorder(node->right);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

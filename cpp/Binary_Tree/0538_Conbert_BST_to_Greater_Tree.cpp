
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
   * use of the characteristic of BST
   * inorder traversal of a BST is ascending order
   * if we can reverse the inorder traversal, then we get descending order
   * so every node's value will be the current sum
   * */
  TreeNode* convertBST(TreeNode* root) {
    traverse(root);
    return root;
  }

  int sum = 0;

  void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->right);
    sum += root->val;
    root->val = sum;
    traverse(root->left);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

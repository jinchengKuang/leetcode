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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    if (val > root->val) root->right = insertIntoBST(root->right, val);
    return root;
  }

  /*
  * 2nd solution iterative
  * */
  TreeNode *insertIntoBST2(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    TreeNode *pre = root, *cur = root;
    while (cur) {
      pre = cur;
      if (val < cur->val) cur = cur->left;
      else cur = cur->right;
    }
    if (val < pre->val) pre->left = new TreeNode(val);
    else pre->right = new TreeNode(val);
    return root;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

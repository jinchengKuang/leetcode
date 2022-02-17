using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  /*
   * 1st solution recursive
   * */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    else return root;
  }

  /*
   * 2nd sollution iterative
   * */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (root) {
      if (p->val < root->val && q->val < root->val) root = root->left;
      else if (p->val > root->val && q->val > root->val) root = root->right;
      else return root;
    }
    return root;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

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
  TreeNode *searchBST(TreeNode *root, int val) {
    if (!root || val == root->val) return root;
    if (val < root->val) return searchBST(root->left, val);
    if (val > root->val) return searchBST(root->right, val);
    return nullptr;
  }

  /*
   * 2nd solution iterative
   * */
  TreeNode *searchBST2(TreeNode *root, int val) {
    while (root) {
      if (val == root->val) return root;
      if (val < root->val) root = root->left;
      else if (val > root->val) root = root->right;
    }
    return nullptr;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

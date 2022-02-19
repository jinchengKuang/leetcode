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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) return root;
    if (root->val == key) {
      if (!root->left && !root->right) {
        delete root;
        return nullptr;
      } else if (!root->left) {
        TreeNode *node = root->right;
        delete root;
        return node;
      } else if (!root->right) {
        TreeNode *node = root->left;
        delete root;
        return node;
      } else {
        TreeNode *cur = root->right;
        while (cur->left) cur = cur->left;
        cur->left = root->left;
        TreeNode *node = root;
        root = root->right;
        delete node;
        return root;
      }
    }

    if (key < root->val) root->left = deleteNode(root->left, key);
    if (key > root->val) root->right = deleteNode(root->right, key);
    return root;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
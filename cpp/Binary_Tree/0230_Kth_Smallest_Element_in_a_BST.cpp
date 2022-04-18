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
   * Use BST
   * inorder of BST is in ascending order
   * we can check if it is the kth element during recursion
   * */
  int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return res;
  }

  int idx = 0;
  int res = 0;

  void inorder(TreeNode* node, int& k) {
    if (!node) return;
    inorder(node->left, k);
    ++idx;
    if (idx == k) {
      res = node->val;
      return;
    }
    inorder(node->right, k);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

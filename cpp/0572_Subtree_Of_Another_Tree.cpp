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
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    return isSameTree(root, subRoot) || (root->left && isSubtree(root->left, subRoot)) ||
           (root->right && isSubtree(root->right, subRoot));
  }

  bool isSameTree(TreeNode *node1, TreeNode *node2) {
    if (node1 == nullptr && node2 == nullptr) return true;
    if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) return false;
    return isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
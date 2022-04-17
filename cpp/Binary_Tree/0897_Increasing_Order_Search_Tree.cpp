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
  TreeNode* resNode;

  TreeNode* increasingBST(TreeNode* root) {
    TreeNode* dummyHead = new TreeNode(0);
    resNode = dummyHead;
    inorder(root);
    return dummyHead->right;
  }

  void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);

    resNode->right = node;
    node->left = nullptr;
    resNode = node;

    inorder(node->right);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

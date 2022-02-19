#include <iostream>
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
  int maxDepth1(TreeNode *root) {
    if (!root) return 0;
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    return max(leftMax, rightMax) + 1; // +1 is root node
  }

  int maxDepth2(TreeNode *root) {
    if (root == nullptr) return 0;
    int depth = 0;
    queue < TreeNode * > q;
    q.emplace(root);
    while (!q.empty()) {
      depth++;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
      }
    }
    return depth;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

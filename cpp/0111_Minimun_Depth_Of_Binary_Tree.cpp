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
  /*
   * 1st solution BFS
   * */
  int minDepth1(TreeNode *root) {
    if (root == nullptr) return 0;
    int min = 0;
    queue < TreeNode * > q;
    q.emplace(root);
    while (!q.empty()) {
      int size = q.size();
      min++;
      for (int i = 0; i < size; ++i) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
        if (!node->left && !node->right) return min;
      }
    }
    return min;
  }

  /*
   * 2nd solution recursive
   * */
  int minDepth2(TreeNode *root) {
    if (root == nullptr) return 0;
    int l = minDepth2(root->left), r = minDepth2(root->right);
    if (root->left && root->right) return 1 + min(l, r);
    return 1 + max(l, r);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

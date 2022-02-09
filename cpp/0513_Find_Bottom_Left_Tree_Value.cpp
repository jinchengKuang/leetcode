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
   * 1st solution level order iterative
   * */
  int findBottomLeftValue(TreeNode *root) {
    queue < TreeNode * > q;
    q.emplace(root);
    int res = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = q.front();
        q.pop();
        if (i == 0) res = node->val;
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
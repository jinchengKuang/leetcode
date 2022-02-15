#include <stack>

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
  TreeNode *pre = nullptr;

  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    bool left = isValidBST(root->left);
    if (pre && root->val <= pre->val) return false;
    pre = root;
    bool right = isValidBST(root->right));
    return left && right;
  }

  /*
   * 2nd soluiton iterative
   * */
  bool isValidBST2(TreeNode *root) {
    stack < TreeNode * > stk;
    TreeNode *pre = nullptr;
    TreeNode *cur = root;
    while (cur || !stk.empty()) {
      if (cur) {
        stk.emplace(cur);
        cur = cur->left;
      } else {
        cur = stk.top();
        stk.pop();
        if (pre && pre->val >= cur->val) return false;
        pre = cur;
        cur = cur->right;
      }
    }
    return true;
  }
}

};
//leetcode submit region end(Prohibit modification and deletion)

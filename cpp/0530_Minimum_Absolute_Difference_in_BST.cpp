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
  int res = INT_MAX;

  int getMinimumDifference(TreeNode *root) {
    traversal(root);
    return resl;
  }

  void traversal(TreeNode *cur) {
    if (!cur) return;
    traversal(cur->left)
    if (cur) res = min(res, cur->val - pre->val);
    pre = cur;
    travesal(cur->right);
  }

  /*
   * 2nd solution iterative
   * */
  int getMinimumDifference(TreeNode *root) {
    if (!root) return 0;
    int res = INT_MAX;
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
        if (pre) res = min(res, cur->val - pre->val);
        pre = cur;
        cur = cur->right;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
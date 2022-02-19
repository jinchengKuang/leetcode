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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) return true;
    else if (p == nullptr || q == nullptr) return false;
    else if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  /*
  * 2nd solution iterative
  * */
  bool isSameTree2(TreeNode *p, TreeNode *q) {
    stack < TreeNode * > stk;
    stk.emplace(p);
    stk.emplace(q);
    while (!stk.empty() && !stk.empty()) {
      TreeNode *pNode = stk.top();
      stk.pop();
      TreeNode *qNode = stk.top();
      stk.pop();

      if (pNode == nullptr && qNode == nullptr) continue;
      if (pNode == nullptr || qNode == nullptr) return false;
      else if (pNode->val != qNode->val) return false;

      stk.emplace(pNode->left);
      stk.emplace(qNode->left);
      stk.emplace(pNode->right);
      stk.emplace(qNode->right);
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

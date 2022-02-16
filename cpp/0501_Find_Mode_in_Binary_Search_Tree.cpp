#include <vector>
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
  vector<int> res;
  int count = 0;
  int maxCount = 0;
  TreeNode *pre = nullptr;

  vector<int> findMode(TreeNode *root) {
    traversal(root);
    return res;
  }

  void traversal(TreeNode *cur) {
    if (!cur) return;
    traversal(cur->left);

    if (!pre) count = 1;
    else if (pre->val == cur->val)count++;
    else count = 1;

    if (count == maxCount) res.emplace_back(cur->val);
    if (count > maxCount) {
      maxCount = count;
      res.clear();
      res.emplace_back(cur->val);
    }

    traversal(cur->right);
    return;
  }

  /*
   * 2nd solution iterative
   * */
  vector<int> findMode(TreeNode *root) {
    if (!root) return {};
    vector<int> res;
    stack < TreeNode * > stk;
    TreeNode *pre = nullptr;
    TreeNode *cur = root;
    int count = 0;
    int maxCount = 0;
    while (cur || !stk.empty()) {
      if (cur) {
        stk.emplace(cur);
        cur = cur->left;
      } else {
        cur = stk.top();
        stk.pop();

        if (!pre) count = 1;
        else if (pre->val == cur->val) count++;
        else count = 1;

        if (count == maxCount) res.emplace_back(cur->val);
        if (count > maxCount) {
          res.clear();
          res.emplace_back(cur->val);
          maxCount = count;
        }

        pre = cur;
        cur = cur->right;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

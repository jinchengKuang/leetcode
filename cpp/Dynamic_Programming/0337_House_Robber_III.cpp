#include <vector>

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
  int rob(TreeNode* root) {
    vector<int> result = dp(root);
    return max(result[0], result[1]);
  }

  vector<int> dp(TreeNode* cur) {
    if (cur == nullptr) return {0, 0};
    vector<int> left = dp(cur->left);
    vector<int> right = dp(cur->right);
    int valRob = cur->val + left[0] + right[0];
    int valNoRob = max(left[0], left[1]) + max(right[0], right[1]);
    return {valNoRob, valRob};
  }
};
//leetcode submit region end(Prohibit modification and deletion)
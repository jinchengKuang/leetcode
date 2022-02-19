#include <vector>
#include <queue>
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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return compare(root->left, root->right);
  }

  bool compare(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right != nullptr) return false;
    else if (left != nullptr && right == nullptr) return false;
    else if (left == nullptr && right == nullptr) return true;
    else if (left->val != right->val) return false;
    return compare(left->left, right->right) && compare(left->right, right->left);
  }

  /*
   * 2nd solution iterative;
   * */
  bool isSymmetric2(TreeNode *root) {
    if (root == nullptr) return true;
    queue < TreeNode * > q;
    q.emplace(root->left);
    q.emplace(root->right);

    while (!q.empty()) {
      TreeNode *left = q.front();
      q.pop();
      TreeNode *right = q.front();
      q.pop();

      if (left == nullptr && right == nullptr) continue;

      if (left == nullptr || right == nullptr || (left->val != right->val)) return false;

      q.emplace(left->left);
      q.emplace(right->right);
      q.emplace(left->right);
      q.emplace(right->left);
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

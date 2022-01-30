#include <vector>
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
  vector<int> rightSideView1(TreeNode *root) {
    if (root == nullptr) return {};
    vector<int> res;
    queue < TreeNode * > q;
    q.emplace(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->left) q.emplace(cur->left);
        if (cur->right) q.emplace(cur->right);
        if (i == size - 1) res.emplace_back(cur->val);
      }
    }
    return res;
  }

  /*
 * 2nd solution DFS
 * */
  vector<int> rightSideView2(TreeNode *root) {
    if (root == nullptr) return {};
    vector<int> res;
    traverse(root, res, 0);
    return res;
  }

  void traverse(TreeNode *node, vector<int> &res, int level) {
    if (node == nullptr) return;
    if (level >= res.size()) res.emplace_back(node->val);
    else res[level] = node->val;
    traverse(node->left, res, level + 1);
    traverse(node->right, res, level + 1);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

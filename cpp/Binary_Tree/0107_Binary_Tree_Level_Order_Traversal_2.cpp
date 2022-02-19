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
  vector <vector<int>> levelOrderBottom1(TreeNode *root) {
    if (root == nullptr) return {};
    vector <vector<int>> res;
    queue < TreeNode * > q;
    q.emplace(root);
    while (!q.empty()) {
      vector<int> vec;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        vec.emplace_back(cur->val);
        if (cur->left) q.emplace(cur->left);
        if (cur->right) q.emplace(cur->right);
      }
      res.emplace_back(vec);
    }
    reverse(res.begin(), res.end());
    return res;
  }

  /*
 * 2nd solution DFS
 * */
  vector <vector<int>> levelOrderBottom2(TreeNode *root) {
    if (root == nullptr) return {};
    vector <vector<int>> res;
    traverse(res, root, 0);
    reverse(res.begin(), res.end());
    return res;
  }

  void traverse(vector <vector<int>> &vec, TreeNode *node, int level) {
    if (node == nullptr) return;
    if (level >= vec.size()) vec.emplace_back(vector < int > {node->val});
    else vec[level].emplace_back(node->val);
    traverse(vec, node->left, level + 1);
    traverse(vec, node->right, level + 1);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

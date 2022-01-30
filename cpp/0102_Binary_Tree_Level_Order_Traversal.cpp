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
  /*
   * 1st solution BFS
   * */
public:
  vector <vector<int>> levelOrder1(TreeNode *root) {
    if (root == nullptr) return {};
    vector <vector<int>> res;
    queue < TreeNode * > que;
    que.push(root);
    while (!que.empty()) {
      vector<int> vec;
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = que.front();
        que.pop();
        vec.emplace_back(cur->val);
        if (cur->left) que.emplace(cur->left);
        if (cur->right) que.emplace(cur->right);
      }
      res.emplace_back(vec);
    }
    return res;
  }
  /*
   * 2nd solution DFS
   * */
public:
  vector <vector<int>> levelOrder2(TreeNode *root) {
    vector <vector<int>> res;
    traverse(root, res, 0);
    return res;
  }

  void traverse(TreeNode *node, vector <vector<int>> &vec, int level) {
    if (node == nullptr) return;
    if (level >= vec.size()) vec.emplace_back(vector < int > {node->val});
    else vec[level].emplace_back(node->val);
    traverse(node->left, vec, level + 1);
    traverse(node->right, vec, level + 1);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

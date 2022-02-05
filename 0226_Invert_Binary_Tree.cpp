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
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return root;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }

  /*
   * 2nd solution DFS
   * */
  TreeNode *invertTree2(TreeNode *root) {
    if (root == nullptr) return root;
    stack < TreeNode * > stk;
    stk.emplace(root);
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      swap(node->left, node->right);
      if (node->right) stk.emplace(node->right);
      if (node->left) stk.emplace(node->left);
    }
    return root;
  }

  /*
   * 3rd solution BFS
   * */
  TreeNode *invertTree3(TreeNode *root) {
    if (root == nullptr) return root;
    queue < TreeNode * > q;
    q.emplace(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = q.front();
        q.pop();
        swap(node->left, node->right);
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
      }
    }
    return root;
  }

};
//leetcode submit region end(Prohibit modification and deletion)

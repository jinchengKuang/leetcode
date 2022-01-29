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
  /*
   * 1st solution
   * Recursive
   * */
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    traverse(root, res);
    return res;
  }

  void traverse(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) return;
    traverse(cur->left, vec);
    vec.emplace_back(cur->val);
    traverse(cur->right, vec);
  }

/*
 * 2nd solution
 * Iterative
 * */
public:
  vector<int> inorderTraversal2(TreeNode *root) {
    vector<int> res{};
    stack < TreeNode * > stk;
    TreeNode *cur = root;
    while (cur != nullptr || !stk.empty()) {
      if (cur != nullptr) {
        stk.emplace(cur);
        cur = cur->left;
      } else {
        cur = stk.top();
        stk.pop();
        res.emplace_back(cur->val);
        cur = cur->right;
      }
    }
    return res;
  }

/*
 * 3rd solution
 * Universal way to Iterative
 * */
public:
  vector<int> inorderTraversal3(TreeNode *root) {
    vector<int> res{};
    stack < TreeNode * > stk;
    if (root != nullptr) stk.emplace(root);
    while (!stk.empty()) {
      TreeNode *cur = stk.top();
      if (cur != nullptr) {
        stk.pop();
        if (cur->right) stk.emplace(cur->right);
        stk.push(cur);
        stk.push(nullptr);
        if (cur->left) stk.emplace(cur->left);
      } else {
        stk.pop();
        cur = stk.top();
        stk.pop();
        res.emplace_back(cur->val);
      }
    }
    return res;
  }

};
//leetcode submit region end(Prohibit modification and deletion)

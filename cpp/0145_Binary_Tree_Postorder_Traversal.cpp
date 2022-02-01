#include <vector>
#include <stack>
#include <algorithm>

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
  vector<int> PostorderTraversal1(TreeNode *root) {
    vector<int> res;
    traverse(root, res);
    return res;
  }

  void traverse(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) return;
    vec.emplace_back(cur->val);
    traverse(cur->left, vec);
    traverse(cur->right, vec);
  }

/*
 * 2nd solution
 * Iterative
 * */
public:
  vector<int> PostorderTraversal2(TreeNode *root) {
    if (root == nullptr) return {};
    vector<int> res;
    stack < TreeNode * > stk;
    stk.emplace(root);
    while (!stk.empty()) {
      TreeNode *cur = stk.top();
      stk.pop();
      res.emplace_back(cur->val);
      if (cur->left) stk.emplace(cur->left);
      if (cur->right) stk.emplace(cur->right);
    }
    reverse(res.begin(), res.end());
    return res;
  }

/*
 * 3rd solution
 * Universal way to Iterative
 * */
public:
  vector<int> PostorderTraversal3(TreeNode *root) {
    vector<int> res{};
    stack < TreeNode * > stk;
    if (root != nullptr) stk.emplace(root);
    while (!stk.empty()) {
      TreeNode *cur = stk.top();
      if (cur != nullptr) {
        stk.pop();
        stk.push(cur);
        stk.push(nullptr);
        if (cur->right) stk.emplace(cur->right);
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

#include <iostream>
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
  vector <string> binaryTreePaths(TreeNode *root) {
    vector <string> res;
    vector<int> path;
    traverse(root, path, res);
    return res;
  }

  void traverse(TreeNode *node, vector<int> &path, vector <string> &res) {
    path.emplace_back(node->val);
    if (!node->left && !node->right) {
      string strPath;
      for (int i = 0; i < path.size() - 1; ++i) {
        strPath = strPath + to_string(path[i]) + "->";
      }
      strPath += to_string(path[path.size() - 1]);
      res.emplace_back(strPath);
      return;
    }
    if (node->left) {
      traverse(node->left, path, res);
      path.pop_back();
    }
    if (node->right) {
      traverse(node->right, path, res);
      path.pop_back();
    }
  }

  /*
   * 2nd solution recursive (simplified)
   * */
  vector <string> binaryTreePaths2(TreeNode *root) {
    vector <string> res;
    string path;
    traversal(root, path, res);
    return res;
  }

  void traversal(TreeNode *node, string path, vector <string> &res) {
    path += to_string(node->val);
    if (!node->left && !node->right) {
      res.emplace_back(path);
      return;
    }
    if (node->left) traversal(node->left, path + "->", res);
    if (node->right) traversal(node->right, path + "->", res);
  }

  /*
   * 3rd solution iterative
   * */
  vector <string> binaryTreePaths3(TreeNode *root) {
    if (!root) return {};
    vector <string> res;

    stack < TreeNode * > nodeStk;
    nodeStk.emplace(root);

    stack <string> pathStk;
    pathStk.emplace(to_string(root->val));

    while (!nodeStk.empty()) {
      TreeNode *node = nodeStk.top();
      nodeStk.pop();

      string path = pathStk.top();
      pathStk.pop();

      if (!node->left && !node->right) res.emplace_back(path);

      if (node->right) {
        nodeStk.emplace(node->right);
        pathStk.emplace(path + "->" + to_string(node->right->val));
      }
      if (node->left) {
        nodeStk.emplace(node->left);
        pathStk.emplace(path + "->" + to_string(node->left->val));
      }
    }

    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <vector>
#include <queue>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  /*
   * 1st solution BFS
   * */
  vector <vector<int>> levelOrder1(Node *root) {
    if (root == nullptr) return {};
    vector <vector<int>> res;
    queue < Node * > q;
    q.emplace(root);
    while (!q.empty()) {
      vector<int> vec;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        Node *node = q.front();
        q.pop();
        vec.emplace_back(node->val);
        for (int j = 0; j < node->children.size(); ++j) {
          if (node->children[j]) q.emplace(node->children[j]);
        }
      }
      res.emplace_back(vec);
    }
    return res;
  }

  /*
   * 2nd solution DFS
   * */
  vector <vector<int>> levelOrder2(Node *root) {
    if (root == nullptr) return {};
    vector <vector<int>> res;
    dfs(root, res);
    return res;
  }

  void dfs(Node *node, vector <vector<int>> &res, int level = 0) {
    if (node == nullptr) return;
    if (level >= res.size()) res.emplace_back(vector < int > {node->val});
    else res[level].emplace_back(node->val);
    for (int i = 0; i < node->children.size(); ++i) {
      if (node->children[i]) dfs(node->children[i], res, level + 1);
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)
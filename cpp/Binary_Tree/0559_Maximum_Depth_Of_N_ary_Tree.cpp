#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
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

class Solution {
public:
  /*
   * 1st solution recursive (Time limit exceed)
   * */
  int maxDepth(Node *root) {
    if (!root) return 0;
    int depth = 0;
    for (int i = 0; i < root->children.size(); ++i) {
      depth = depth > maxDepth(root->children[i]) ? depth : maxDepth(root->children[i]);
    }
    return 1 + depth;
  }

  /*
   * 2nd solution BFS iterative
   * */
  int maxDepth2(Node *root) {
    if (!root) return 0;
    int depth = 0;
    queue < Node * > q;
    q.emplace(root);
    while (!q.empty()) {
      int size = 0;
      depth++;
      for (int i = 0; i < size; ++i) {
        Node *node = q.front();
        q.pop();
        for (int j = 0; j < node->children.size(); ++j) {
          if (node->children[j]) q.emplace(node->children[j]);
        }
      }
    }
    return depth;
  }
};
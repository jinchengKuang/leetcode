#include <vector>
#include <queue>

using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
          : val(_val), left(_left), right(_right), next(_next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr) return root;
    queue < Node * > q;
    q.emplace(root);
    while (!q.empty()) {
      int size = q.size();
      Node *node;
      Node *preNode;
      for (int i = 0; i < size; ++i) {
        if (i == 0) {
          node = q.front();
          preNode = node;
          q.pop();
        } else {
          node = q.front();
          preNode->next = node;
          preNode = node;
          q.pop();
        }
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
      }
    }
    return root;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

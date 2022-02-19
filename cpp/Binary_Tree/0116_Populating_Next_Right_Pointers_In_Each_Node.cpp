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
  /*
   * 1st solution BFS iterative
   * */
  Node *connect1(Node *root) {
    if (root == nullptr) return {};
    queue < Node * > q;
    q.emplace(root);
    while (!q.empty()) {
      Node *node;
      Node *preNode;
      int size = q.size();
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

  /*
   * 2nd solution DFS Recursive
   * */
  Node *connect3(Node *root) {
    if (root == nullptr) return {};
    connectTwoNodes(root->left, root->right);
    return root;
  }

  void connectTwoNodes(Node *left, Node *right) {
    if (left == nullptr || right == nullptr) return;
    left->next = right;
    connectTwoNodes(left->left, left->right);
    connectTwoNodes(left->right, right->left);
    connectTwoNodes(right->left, right->right);
  }

  /*
   * 3rd solution DFS Recursive
   * */
  Node *connect2(Node *root) {
    if (root == nullptr || root->left == nullptr || root->right == nullptr) return root;
    root->left->next = root->right;
    if (root->next != nullptr) root->right->next = root->next->left;
    connect2(root->left);
    connect2(root->right);
    return root;
  }

};
//leetcode submit region end(Prohibit modification and deletion)



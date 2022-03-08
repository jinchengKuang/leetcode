
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
private:
  int res = 0;

  int traversal(TreeNode* node) {
    /*
     * state 0: un-monitored;
     * state 1: monitored;
     * state 2: camera;
     * */
    if (node == nullptr) return 1;
    int left = traversal(node->left);
    int right = traversal(node->right);
    if (left == 1 && right == 1) return 0;
    else if (left == 0 || right == 0) {
      res++;
      return 2;
    } else return 1;
  }

public:
  int minCameraCover(TreeNode* root) {
    res = 0;
    if (traversal(root) == 0) res++;
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return traversal(nums, 0, nums.size());
  }

  TreeNode *traversal(vector<int> nums, int left, int right) {
    if (left >= right) return nullptr;
    int maxValueIndex = left;
    for (int i = left + 1; i < right; ++i) {
      if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
    }
    TreeNode *root = new TreeNode(nums[maxValueIndex]);

    root->left = traversal(nums, left, maxValueIndex);
    root->right = traversal(nums, maxValueIndex + 1, right);

    return root;
  }

  /*
   * 2nd solution monotonic stack
   * */
  TreeNode *constructMaximumBinaryTree2(vector<int> &nums) {
    stack < TreeNode * > stk;
    for (int i = 0; i < nums.size(); ++i) {
      TreeNode *cur = new TreeNode(nums[i]);
      while (stk.size() && stk.top()->val < nums[i]) {
        cur->left = stk.top();
        stk.pop();
      }
      if (stk.size()) stk.top()->right = cur;
      stk.push(cur);
    }
    while (stk.size() != 1) stk.pop();
    return stk.top();
  }
};
//leetcode submit region end(Prohibit modification and deletion)

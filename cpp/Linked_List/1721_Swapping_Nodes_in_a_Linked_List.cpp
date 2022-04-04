using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  /*
   * two pointers
   * dummy->1->2->3->4->5, k=2
   *  |slow    |fast
   *  dummy->1->2->3 ->4->5->null
   *                   |slow |fast
   *            |node1 |node2
   * dummy->1->4->3->2->5
   * note: SWAP VALUES
   * */
  ListNode* swapNodes(ListNode* head, int k) {
    // 1. use dummy head
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    // 2. slow and fast pointer
    // 2.1 fast pointer go k steps, slow pointer remain at head
    ListNode* slow = dummyHead;
    ListNode* fast = slow;
    while (k-- && fast) {
      fast = fast->next;
    }
    ListNode* node1 = fast; // node1 is the fist kth node
    // 2.2 slow and fast move together, so slow is pointing to the last kth node
    while (fast) {
      slow = slow->next;
      fast = fast->next;
    }
    ListNode* node2 = slow; // node2 is the last kth node
    // 3. swap node1 and node2
    swap(node1->val, node2->val);
    return dummyHead->next;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

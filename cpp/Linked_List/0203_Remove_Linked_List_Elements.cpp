using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
   * 1st solution recursive
   * */
  ListNode *removeElements(ListNode *head, int val) {
    if (!head) return head;
    head->next = removeElements(head->next, val);
    if (head->val == val) return head->next;
    else return head;
  }

  /*
   * 2nd solution iterative
   * */
  ListNode *removeElements2(ListNode *head, int val) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    while (cur->next) {
      if (cur->next->val == val) {
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      } else {
        cur = cur->next;
      }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *temp = head->next;
    head->next = swapPairs(temp->next);
    temp->next = head;
    return temp;
  }

  /*
   * 2nd solution iterative
   */
  ListNode *swapPairs2(ListNode *head) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;

    while (cur->next && cur->next->next) {
      ListNode *temp1 = cur->next;
      ListNode *temp2 = cur->next->next->next;
      cur->next = cur->next->next;
      cur->next->next = temp1;
      cur->next->next->next = temp2;

      cur = cur->next->next;
    }

    return dummyHead->next;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

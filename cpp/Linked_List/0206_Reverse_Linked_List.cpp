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
   * 1st solution recursive - reverse from back
   * */
  ListNode *reverseList(ListNode *head) {
    if (!head) return nullptr;
    if (!head->next) return head;
    ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
  }

  /*
   * 2nd solution two pointers
   * */
  ListNode *reverseList2(ListNode *head) {
    ListNode *pre = nullptr, *cur = head, *temp = nullptr;
    while (cur) {
      temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;
  }

  /*
   * 3rd solution recursive (based on two pointers)
   * */
  ListNode *reverseList3(ListNode *head) {
    return reverse(nullptr, head);
  }

  ListNode *reverse(ListNode *pre, ListNode *cur) {
    if (!cur) return pre;
    ListNode *temp = cur->next;
    cur->next = pre;
    return reverse(cur, temp);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

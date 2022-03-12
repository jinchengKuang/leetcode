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
   * 1st solution recursive
   * */
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    else if (!list2) return list1;
    if (list1->val > list2->val) {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    } else {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
  }

  /*
   * 2nd solution iterative
   * */
  ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* p = dummyHead;
    ListNode* p1 = list1;
    ListNode* p2 = list2;
    while (p1 && p2) {
      if (p1->val > p2->val) {
        p->next = p2;
        p2 = p2->next;
      } else {
        p->next = p1;
        p1 = p1->next;
      }
      p = p->next;
    }
    if (p1) p->next = p1;
    if (p2) p->next = p2;
    return dummyHead->next;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

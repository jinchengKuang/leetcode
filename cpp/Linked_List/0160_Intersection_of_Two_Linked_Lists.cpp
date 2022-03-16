using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(NULL) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  /*
   * 1st solution length difference
   * */
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = 0, lenB = 0;
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while (p1) {
      p1 = p1->next;
      lenA++;
    }
    while (p2) {
      p2 = p2->next;
      lenB++;
    }
    int lenDiff = lenA - lenB;
    if (lenDiff > 0) {
      while (lenDiff > 0) {
        headA = headA->next;
        lenDiff--;
      }
    } else if (lenDiff < 0) {
      while (lenDiff < 0) {
        headB = headB->next;
        lenDiff++;
      }
    }

    while (headA && headB) {
      if (headA->val == headB->val) return p1;
      headA = headA->next;
      headB = headB->next;
    }
    return nullptr;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

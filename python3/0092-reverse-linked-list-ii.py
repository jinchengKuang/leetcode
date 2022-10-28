# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        pre = dummy

        for _ in range(left - 1):
            pre = pre.next

        cur = pre.next
        newHead = None
        for _ in range(right - left + 1):
            tmp = cur.next
            cur.next = newHead
            newHead = cur
            cur = tmp

        pre.next.next = cur
        pre.next = newHead

        return dummy.next

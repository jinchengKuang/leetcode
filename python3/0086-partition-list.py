# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        dummy1, dummy2 = ListNode(), ListNode()
        small, large = dummy1, dummy2
        cur = head
        while cur:
            if cur.val < x:
                small.next = cur
                small = small.next
            else:
                large.next = cur
                large = large.next
            temp = cur.next
            cur.next = None
            cur = temp
        small.next = dummy2.next
        return dummy1.next

# class Solution:
#     def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
#         small = dummy1 = ListNode()
#         large = dummy2 = ListNode()
#         while head:
#             if head.val < x:
#                 small.next = head
#                 small = small.next
#             else:
#                 large.next = head
#                 large = large.next
#             head = head.next
#         large.next = None
#         small.next = dummy2.next
#         return dummy1.next


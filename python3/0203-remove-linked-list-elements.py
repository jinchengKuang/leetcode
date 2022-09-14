# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: [ListNode], val: int) -> [ListNode]:
        dummy_head = ListNode(0, head)
        cur = dummy_head
        while cur.next:
            if cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return dummy_head.next


def to_linked_list(iterable):
    head = None
    for val in reversed(iterable):
        head = ListNode(val, head)
    return head


def to_native_list(head):
    lst = []
    while head:
        lst.append(head.val)
        head = head.next
    return lst


head = [1, 2, 6, 3, 4, 5, 6]
val = 6
l1 = to_linked_list(head)
result = Solution().removeElements(l1, val)
print(to_native_list(result))  # [1, 2, 3, 4, 5]

head = []
val = 1
l2 = to_linked_list(head)
result = Solution().removeElements(l2, val)
print(to_native_list(result))  # []

head = [7, 7, 7, 7]
val = 7
l3 = to_linked_list(head)
result = Solution().removeElements(l3, val)
print(to_native_list(result))  # []

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: [ListNode], n: int) -> [ListNode]:
        dummy_head = ListNode(0, head)
        slow = fast = dummy_head
        for i in range(n):
            fast = fast.next
        while fast.next:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
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


head = [1, 2, 3, 4, 5]
n = 2
l1 = to_linked_list(head)
result = Solution().removeNthFromEnd(l1, n)  # [1,2,3,5]
print(to_native_list(result))

head = [1]
n = 1
l2 = to_linked_list(head)
result = Solution().removeNthFromEnd(l2, n)  # []
print(to_native_list(result))

head = [1, 2]
n = 1
l3 = to_linked_list(head)
result = Solution().removeNthFromEnd(l3, n)  # [1]
print(to_native_list(result))

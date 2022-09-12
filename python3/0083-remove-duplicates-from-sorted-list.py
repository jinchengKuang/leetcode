# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: [ListNode]) -> [ListNode]:
        if not head or not head.next:
            return head
        slow, fast = head, head.next
        while fast:
            if slow.val != fast.val:
                slow.next = fast
                slow = slow.next
            fast = fast.next
        slow.next = None
        return head


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


l1 = to_linked_list([1, 1, 2])
result = Solution().deleteDuplicates(l1)
print(to_native_list(result))

l2 = to_linked_list([1, 1, 2, 3, 3])
result = Solution().deleteDuplicates(l2)
print(to_native_list(result))

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # iterative
    def reverseList(self, head: [ListNode]) -> [ListNode]:
        cur = head
        pre = None
        while cur:
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        return pre

    #recursive
    def reverseList2(self, head: [ListNode]) -> [ListNode]:
        if not head or not head.next:
            return head
        else:
            last_node = self.reverseList2(head.next)
            head.next.next = head
            head.next = None
        return last_node

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
l1 = to_linked_list(head)
result = Solution().reverseList(l1)
print(to_native_list(result))

head = [1, 2]
l2 = to_linked_list(head)
result = Solution().reverseList(l2)
print(to_native_list(result))

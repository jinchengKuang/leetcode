# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: [ListNode]) -> [ListNode]:
        dummy_head = ListNode(0, head)
        pre = dummy_head

        while pre.next and pre.next.next:
            cur = pre.next
            post = pre.next.next

            #   0  ->  1  ->  2  ->  3
            #  pre    cur    post
            cur.next = post.next  # 1 -> 3
            post.next = cur  # 2 -> 1
            pre.next = post  # 0 -> 2

            pre = pre.next.next
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


head = [1, 2, 3, 4]
l1 = to_linked_list(head)
result = Solution().swapPairs(l1)
print(to_native_list(result))  # [2, 1, 4, 3]

head = []
l2 = to_linked_list(head)
result = Solution().swapPairs(l2)
print(to_native_list(result))  # []

head = [1]
l3 = to_linked_list(head)
result = Solution().swapPairs(l3)
print(to_native_list(result))  #[1]

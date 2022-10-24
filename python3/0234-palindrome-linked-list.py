# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        def reverse(node):
            pre = None
            while node:
                tmp = node.next
                node.next = pre
                pre = node
                node = tmp
            return pre

        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        if fast:
            slow = slow.next

        left, right = head, reverse(slow)
        while right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next

        return True

        # use stack
        # slow = fast = head
        # while fast and fast.next:
        #     fast = fast.next.next
        #     slow = slow.next
        #
        # if fast:
        #     slow = slow.next
        #
        # left, right = head, slow
        # stk = []
        # while right:
        #     stk.append(right.val)
        #     right = right.next
        #
        # while stk:
        #     if stk.pop() != left.val:
        #         return False
        #     left = left.next
        #
        # return True

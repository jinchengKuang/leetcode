# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> [ListNode]:
        """
        find the length of A and B
        longer List go first by steps(A-B)
        move forward together
        """
        # len_a = len_b = 0
        # p_a, p_b = headA, headB
        # while p_a:
        #     p_a = p_a.next
        #     len_a += 1
        # while p_b:
        #     p_b = p_b.next
        #     len_b += 1
        # cur_a, cur_b = headA, headB
        # if len_b > len_a:
        #     len_a, len_b = len_b, len_a
        #     cur_a, cur_b = cur_b, cur_a
        # step = len_a - len_b
        # while step:
        #     cur_a = cur_a.next
        #     step -= 1
        # while cur_a:
        #     if cur_a == cur_b:
        #         return cur_a
        #     cur_a = cur_a.next
        #     cur_b = cur_b.next

        """
        concatenate A and B
        if there is an intersection, then it's a loop
        if no intersection, then no loop, both list hit None 
        """
        if headA and headB:
            cur_a, cur_b = headA, headB
            while cur_a is not cur_b:
                cur_a = cur_a.next if cur_a else headB
                cur_b = cur_b.next if cur_b else headA
            return cur_a

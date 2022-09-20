class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class MyLinkedList:

    def __init__(self):
        self._head = Node(0)
        self._count = 0

    def get(self, index: int) -> int:
        if 0 <= index < self._count:
            node = self._head
            for _ in range(0, index + 1):
                node = node.next
                index -= 1
            return node.val
        return -1

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self._count, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self._count:
            return
        self._count += 1
        node = Node(val)
        pre, cur = Node(0), self._head
        for _ in range(0, index + 1):
            pre = cur
            cur = cur.next
        pre.next = node
        node.next = cur

    def deleteAtIndex(self, index: int) -> None:
        if 0 <= index < self._count:
            self._count -= 1
            pre, cur = Node(0), self._head
            for _ in range(0, index + 1):
                pre = cur
                cur = cur.next
            pre.next = cur.next
            cur.next = None

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)


//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {
public:
  struct LinkedNode {
    int val;
    LinkedNode *next;

    LinkedNode(int val) : val(val), next(nullptr) {}
  };

  MyLinkedList() {
    m_dummyHead = new LinkedNode(0);
    m_size = 0;
  }

  int get(int index) {
    if (index < 0 || index > m_size - 1) return -1;
    LinkedNode *cur = m_dummyHead->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    LinkedNode *newNode = new LinkedNode(val);
    newNode->next = m_dummyHead->next;
    m_dummyHead->next = newNode;
    m_size++;
  }

  void addAtTail(int val) {
    LinkedNode *newNode = new LinkedNode(val);
    LinkedNode *cur = m_dummyHead;
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = newNode;
    m_size++;
  }

  void addAtIndex(int index, int val) {
    if (index > m_size || index < 0) return;
    LinkedNode *newNode = new LinkedNode(val);
    LinkedNode *cur = m_dummyHead;
    while (index--) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    m_size++;
  }

  void deleteAtIndex(int index) {
    if (index > m_size - 1 || index < 0) return;
    LinkedNode *cur = m_dummyHead;
    while (index--) {
      cur = cur->next;
    }
    LinkedNode *tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    m_size--;
  }

private:
  LinkedNode *m_dummyHead;
  int m_size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)

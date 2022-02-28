#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyStack {
public:
  queue<int> q;

  MyStack() {

  }

  void push(int x) {
    q.push(x);
  }

  int pop() {
    int size = q.size();
    while (--size) {
      q.push(q.front());
      q.pop();
    }
    int res = q.front();
    q.pop();
    return res;
  }

  int top() {
    return q.back();
  }

  bool empty() {
    return q.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)

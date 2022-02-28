#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
public:
  stack<int> stkIn;
  stack<int> stkOut;

  MyQueue() {

  }

  void push(int x) {
    stkIn.push(x);
  }

  int pop() {
    if (stkOut.empty()) {
      while (!stkIn.empty()) {
        stkOut.push(stkIn.top());
        stkIn.pop();
      }
    }
    int res = stkOut.top();
    stkOut.pop();
    return res;
  }

  int peek() {
    int res = this->pop();
    stkOut.push(res);
    return res;
  }

  bool empty() {
    return stkIn.empty() && stkOut.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)

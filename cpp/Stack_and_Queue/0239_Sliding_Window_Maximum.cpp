#include <vector>
#include <deque>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  class MonotonicQueue {
  public:
    deque<int> deq;

    void pop(int value) {
      if (!deq.empty() && value == deq.front()) deq.pop_front();
    }

    void push(int value) {
      while (!deq.empty() && value > deq.back()) deq.pop_back();
      deq.push_back(value);
    }

    int front() {
      return deq.front();
    }
  };

  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    MonotonicQueue q;
    vector<int> res;
    for (int i = 0; i < k; ++i) {
      q.push(nums[i]);
    }
    res.push_back(q.front());
    for (int i = k; i < nums.size(); ++i) {
      q.pop(nums[i - k]);
      q.push(nums[i]);
      res.push_back(q.front());
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

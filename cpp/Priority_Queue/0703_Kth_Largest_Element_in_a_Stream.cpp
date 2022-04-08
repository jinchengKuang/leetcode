#include <vector>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * priority queue min heap
 * min heap hold maximan k elments
 * pop the overflow elements
 * each time we use .top() and return
 * */
class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int K;
public:
  KthLargest(int k, vector<int>& nums) {
    this->K = k;
    for (int i = 0; i < nums.size(); ++i) {
      add(nums[i]);
    }
  }

  int add(int val) {
    this->pq.push(val);
    if (this->pq.size() > K) {
      this->pq.pop();
    }
    return this->pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//leetcode submit region end(Prohibit modification and deletion)

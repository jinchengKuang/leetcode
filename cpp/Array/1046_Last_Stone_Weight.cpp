#include <vector>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * use of priority queue
   * */
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (int i = 0; i < stones.size(); ++i) {
      pq.push(stones[i]);
    }
    while (pq.size() > 1) {
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();
      if (x != y) pq.push(x - y);
    }
    return pq.empty() ? 0 : pq.top();
  }
};
//leetcode submit region end(Prohibit modification and deletion)

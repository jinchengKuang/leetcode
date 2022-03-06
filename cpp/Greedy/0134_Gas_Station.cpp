#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int curSum = 0, totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
      totalSum += gas[i] - cost[i];
      curSum += gas[i] - cost[i];
      if (curSum < 0) {
        start = i + 1;
        curSum = 0;
      }
    }
    return (totalSum < 0) ? -1 : start;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

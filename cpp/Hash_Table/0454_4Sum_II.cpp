#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    unordered_map<int, int> map;
    int count = 0;
    for (int num1: nums1) {
      for (int num2: nums2) {
        map[num1 + num2]++;
      }
    }
    for (int num3: nums3) {
      for (int num4: nums4) {
        if (map.find(0 - num3 - num4) != map.end()) count += map[0 - num3 - num4];
      }
    }
    return count;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

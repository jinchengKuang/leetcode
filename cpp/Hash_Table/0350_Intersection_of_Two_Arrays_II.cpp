#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    unordered_map<int, int> nums1_map;
    for (int num: nums1) {
      nums1_map[num]++;
    }
    for (int num: nums2) {
      if (nums1_map[num]) {
        res.emplace_back(num);
        nums1_map[num]--;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

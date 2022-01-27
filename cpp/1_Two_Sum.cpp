#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map; //key is number value, value is index
    for (int i = 0; i < nums.size(); ++i) {
      int num = target - nums[i];
      if (map.find(num) != map.end()) {
        return {map[num], i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
  vector<int> test{2, 7, 11, 15};
  Solution solution;
  vector<int> output = solution.twoSum(test, 9);
  for (int n: output) {
    cout << n << " ";
  }
  return 0;
}
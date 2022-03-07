#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> partitionLabels(string s) {
    int hash[27] = {0};
    for (int i = 0; i < s.size(); ++i) {
      hash[s[i] - 'a'] = i;
    }
    vector<int> res;
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); ++i) {
      right = max(right, hash[s[i] - 'a']);
      if (i == right) {
        res.push_back(right - left + 1);
        left = i + 1;
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

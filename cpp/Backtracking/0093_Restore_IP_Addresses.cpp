#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector <string> res;

  void backtracking(string& s, int start, int pointCount) {
    if (pointCount == 3) {
      if (isValid(s, start, s.size() - 1)) res.push_back(s);
      return;
    }
    for (int i = start; i < s.size(); ++i) {
      if (isValid(s, start, i)) {
        s.insert(s.begin() + i + 1, '.');
        pointCount++;
        backtracking(s, i + 2, pointCount);
        pointCount--;
        s.erase(s.begin() + i + 1);
      } else break;
    }
  }

  bool isValid(const string& s, int start, int end) {
    if (start > end) return false;
    if (s[start] == '0' && start != end) return false;
    int num = 0;
    for (int i = start; i <= end; ++i) {
      num = num * 10 + (s[i] - '0');
      if (num > 255) return false;
    }
    return true;
  }

public:
  vector <string> restoreIpAddresses(string s) {
    if (s.size() > 12) return res;
    backtracking(s, 0, 0);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

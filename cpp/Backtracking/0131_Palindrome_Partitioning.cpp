#include <vector>
#include <string>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<string> path;
  vector<vector<string>> res;

  void backtracking(const string& s, int start) {
    if (start >= s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < s.size(); i++) {
      if (isPalindrome(s, start, i)) {
        string str = s.substr(start, i - start + 1);
        path.push_back(str);
      } else continue;
      backtracking(s, i + 1);
      path.pop_back();
    }
  }

  bool isPalindrome(const string& s, int start, int end) {
    while (end > start) {
      if (s[start++] != s[end--]) return false;
    }
    return true;
  }
  
public:
  vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

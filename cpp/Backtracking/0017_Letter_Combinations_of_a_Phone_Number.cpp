#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  const string letterMap[10] = {
      "",
      "",
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz"
  };
  string s;
  vector <string> res;

  void backtracking(const string& digits, int index) {
    if (index == digits.size()) {
      res.push_back(s);
      return;
    }
    string letters = letterMap[digits[index] - '0'];
    for (int i = 0; i < letters.size(); ++i) {
      s.push_back(letters[i]);
      backtracking(digits, index + 1);
      s.pop_back();
    }
  }

public:
  vector <string> letterCombinations(string digits) {
    if (digits.size() == 0) return res;
    backtracking(digits, 0);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

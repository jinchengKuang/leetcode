#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int record[26] = {0};
    for (int i = 0; i < magazine.size(); ++i) {
      record[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); ++i) {
      record[ransomNote[i] - 'a']--;
      if (record[ransomNote[i] - 'a'] < 0) return false;
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

#include <string>

using namespace std;

class Solution {
public:
  /*
   * two pointers and greedy
   * */
  bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] == s[right]) {
        left++;
        right--;
      } else {
        return isValidPalindrome(s, left + 1, right) || isValidPalindrome(s, left, right - 1);
      }
    }
    return true;
  }

  bool isValidPalindrome(const string& s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) return false;
    }
    return true;
  }
};
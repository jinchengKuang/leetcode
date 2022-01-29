class Solution {
public:
	bool isPalindrome(int x) {
		if (x == 0) {
			return true;
		}
		else if (x < 0 || x % 10 == 0) {
			return false;
		}
		else {
			int originNum = x;
			int reverseNum = 0;
			while (x != 0) {
				int remainder = x % 10;
				x /= 10;
				if (reverseNum > INT_MAX / 10 || reverseNum < INT_MAX / (-10)) {
					return false;
				}
				reverseNum = reverseNum * 10 + remainder;
			}
			return (reverseNum == originNum) ? true : false;
		}
	}
};
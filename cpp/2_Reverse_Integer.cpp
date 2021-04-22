class Solution {
public:
	int reverse(int x) {
		int newNum = 0;
		while (x != 0) {
			int remainder = x % 10;
			x /= 10;
			if (newNum > INT_MAX / 10 || newNum < INT_MAX / (-10)) {
				return 0;
			}
			newNum = newNum * 10 + remainder;
		}
		return newNum;
	}
};
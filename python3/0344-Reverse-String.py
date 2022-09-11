from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # left, right = 0, len(s) - 1
        # while left <= right:
        #     s[left], s[right] = s[right], s[left]
        #     left += 1
        #     right -= 1
        str[::-1]


s = Solution()
str = ["h", "e", "l", "l", "o"]
s.reverseString(str)
print(str)  # ["o","l","l","e","h"]

str = ["H", "a", "n", "n", "a", "h"]
print(str)  # ["h","a","n","n","a","H"]

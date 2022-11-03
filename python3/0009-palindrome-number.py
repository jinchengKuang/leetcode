class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        tmp = x
        y = 0
        while tmp > 0:
            y = y * 10 + tmp % 10
            tmp //= 10
        return x == y

    def isPalindrome2(self, x: int) -> bool:
        if x < 0:
            return False
        return str(x) == str(x)[::-1]


x = 121
print(Solution().isPalindrome(x))  # True
print(Solution().isPalindrome2(x))  # True
x = -121
print(Solution().isPalindrome(x))  # False
print(Solution().isPalindrome2(x))  # False
x = 10
print(Solution().isPalindrome(x))  # False
print(Solution().isPalindrome2(x))  # False
x = 1221
print(Solution().isPalindrome(x))  # True
print(Solution().isPalindrome2(x))  # True
x = 1212
print(Solution().isPalindrome(x))  # False
print(Solution().isPalindrome2(x))  # False

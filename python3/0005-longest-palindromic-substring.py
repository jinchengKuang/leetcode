class Solution:
    def longestPalindrome(self, s: str) -> str:
        def palindrome(subs: str, left: int, right: int) -> str:
            while left >= 0 and right <= len(subs) - 1 and subs[left] == subs[right]:
                left -= 1
                right += 1
            return subs[left + 1:right]

        res = ""
        for i in range(len(s)):
            s1 = palindrome(s, i, i)
            s2 = palindrome(s, i, i + 1)
            res = max([res, s1, s2], key=lambda x: len(x))
        return res


s = Solution()
str = "babad"
print(s.longestPalindrome(str))  # bab or aba

str = "cbbd"
print(s.longestPalindrome(str))  # bb

str = "bb"
print(s.longestPalindrome(str))  # bb

class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])


s = "the sky is blue"
print(Solution().reverseWords(s))  # blue is sky the

s = "  hello world  "
print(Solution().reverseWords(s))  # world hello

s = "a good   example"
print(Solution().reverseWords(s))  # example good a

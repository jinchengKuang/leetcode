class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        def reverse_substring(s: str) -> str:
            return s[::-1]

        res = list(s)
        for i in range(0, len(s), 2 * k):
            res[i:i + k] = reverse_substring(res[i:i + k])

        return ''.join(res)


s = "abcdefg"
k = 2
print(Solution().reverseStr(s, k))  # bacdfeg

s = "abcd"
k = 2
print(Solution().reverseStr(s, k))  # bacd

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = dict.fromkeys(range(len(s)), 0)
        res = 0
        left = right = 0
        while right < len(s):
            c = s[right]
            right += 1
            window[c] += 1
            while window[c] > 1:
                d = s[left]
                left += 1
                window[d] -= 1
            res = max(res, right - left)


s = "abcabcbb"

s = "bbbbb"

s = "pwwkew"

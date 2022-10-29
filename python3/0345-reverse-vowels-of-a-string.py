class Solution:
    def reverseVowels(self, s: str) -> str:
        l = list(s)
        vowels = "AaEeIiOoUu"
        left, right = 0, len(l) - 1
        while left < right:
            while l[left] not in vowels and left < right:
                left += 1
            while l[right] not in vowels and left < right:
                right -= 1
            if left < right:
                l[left], l[right] = l[right], l[left]
            left += 1
            right -= 1
        return ''.join(l)

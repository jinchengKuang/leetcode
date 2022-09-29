class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        record = [0] * 26
        for char in s:
            record[ord(char) - ord('a')] += 1
        for char in t:
            record[ord(char) - ord('a')] -= 1
        return all(i == 0 for i in record)


s = "anagram"
t = "nagaram"
print(Solution().isAnagram(s, t))  # True

s = "rat"
t = "car"
print(Solution().isAnagram(s, t))  # False

s = "ab"
t = "a"
print(Solution().isAnagram(s, t))  # False

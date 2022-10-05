class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        record = [0] * 26
        for c in magazine:
            record[ord(c) - ord('a')] += 1
        for c in ransomNote:
            if record[ord(c) - ord('a')] == 0:
                return False
            else:
                record[ord(c) - ord('a')] -= 1
        return True


ransomNote = "a"
magazine = "b"
print(Solution().canConstruct(ransomNote, magazine))  # False

ransomNote = "aa"
magazine = "ab"
print(Solution().canConstruct(ransomNote, magazine))  # False

ransomNote = "aa"
magazine = "aab"
print(Solution().canConstruct(ransomNote, magazine))  # True

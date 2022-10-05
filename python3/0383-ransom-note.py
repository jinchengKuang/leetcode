class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        record = dict()
        for ch in magazine:
            if ch in record:
                record[ch] += 1
            else:
                record[ch] = 1
        for ch in ransomNote:
            if ch in record:
                if record[ch] == 0:
                    return False
                else:
                    record[ch] -= 1
            else:
                return False
        return True

        # record = [0] * 26
        # for c in magazine:
        #     record[ord(c) - ord('a')] += 1
        # for c in ransomNote:
        #     if record[ord(c) - ord('a')] == 0:
        #         return False
        #     else:
        #         record[ord(c) - ord('a')] -= 1
        # return True


ransomNote = "a"
magazine = "b"
print(Solution().canConstruct(ransomNote, magazine))  # False

ransomNote = "aa"
magazine = "ab"
print(Solution().canConstruct(ransomNote, magazine))  # False

ransomNote = "aa"
magazine = "aab"
print(Solution().canConstruct(ransomNote, magazine))  # True

from typing import List


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        res = -1
        left, right = 0, len(letters) - 1
        while left <= right:
            mid = (left + right) // 2
            if letters[mid] > target:
                res = letters[mid]
                right = mid - 1
            else:
                left = mid + 1

        return res if res != -1 else letters[0]


s = Solution()
letters = ["c", "f", "j"]
target = "a"
print(s.nextGreatestLetter(letters, target))  # "c"

letters = ["c", "f", "j"]
target = "c"
print(s.nextGreatestLetter(letters, target))  # "f"

letters = ["c", "f", "j"]
target = "d"
print(s.nextGreatestLetter(letters, target))  # "f"

letters = ['a', 'b']
target = 'z'
print(s.nextGreatestLetter(letters, target))  # "a"

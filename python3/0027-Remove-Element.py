from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slow, fast = 0, 0
        while fast < len(nums):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow


s = Solution()
nums = [3, 2, 2, 3]
val = 3
print(s.removeElement(nums, val))  # 2

nums = [0, 1, 2, 2, 3, 0, 4, 2]
val = 2
print(s.removeElement(nums, val))  # 5

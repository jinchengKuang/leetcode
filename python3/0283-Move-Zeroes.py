import ssl
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = fast = 0
        while fast < len(nums):
            if nums[fast] != 0:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        for i in range(slow, len(nums)):
            nums[i] = 0


s = Solution()
nums = [0, 1, 0, 3, 12]
s.moveZeroes(nums)
print(nums)  # [1,3,12,0,0]

nums = [0]
s.moveZeroes(nums)
print(nums)  # [0]

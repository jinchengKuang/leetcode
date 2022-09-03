from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        leftbound = left

        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        rightbound = right
        return [leftbound, rightbound] if leftbound <= rightbound else [-1, -1]


s = Solution()
nums = [5, 7, 7, 8, 8, 10]
target = 8
print(s.searchRange(nums, target))

target = 6
print(s.searchRange(nums, target))

nums = []
target = 0
print(s.searchRange(nums, target))

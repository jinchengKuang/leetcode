from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                return mid
        return left


s = Solution()

nums = [1, 3, 5, 6]
target = 5
print(s.searchInsert(nums, target))

nums = [1, 3, 5, 6]
target = 2
print(s.searchInsert(nums, target))

nums = [1, 3, 5, 6]
target = 7
print(s.searchInsert(nums, target))

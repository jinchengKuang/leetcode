from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                return mid
        return -1


nums = [-1, 0, 3, 5, 9, 12]
target = 9
s = Solution()
print(s.search(nums, target))

nums = [-1, 0, 3, 5, 9, 12]
target = 2
s = Solution()
print(s.search(nums, target))

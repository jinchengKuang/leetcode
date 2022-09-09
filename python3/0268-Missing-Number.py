from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sorted_nums = sorted(nums)
        left, right = 0, len(nums) - 1
        res = -1
        while left <= right:
            mid = (left + right) // 2
            if sorted_nums[mid] > mid:
                right = mid - 1
                res = mid
            else:
                left = mid + 1
        return res if res != -1 else len(nums)


s = Solution()
nums = [3, 0, 1]  # 2
print(s.missingNumber(nums))

nums = [0, 1]  # 2
print(s.missingNumber(nums))

nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]  # 8
print(s.missingNumber(nums))

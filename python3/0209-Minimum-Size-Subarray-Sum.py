from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        res = len(nums) + 1  # ensure initial res is largest
        temp_sum = 0
        start = 0
        for end in range(len(nums)):
            temp_sum += nums[end]
            while temp_sum >= target:
                res = min(res, end - start + 1)
                temp_sum -= nums[start]
                start += 1
        return 0 if res == len(nums) + 1 else res


s = Solution()
nums = [2, 3, 1, 2, 4, 3]
target = 7
print(s.minSubArrayLen(target, nums))  # 2

target = 4
nums = [1, 4, 4]
print(s.minSubArrayLen(target, nums))  # 1

target = 11
nums = [1, 1, 1, 1, 1, 1, 1, 1]
print(s.minSubArrayLen(target, nums))  # 0

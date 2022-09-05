from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        left, right, idx = 0, n - 1, n - 1
        while left <= right:
            left_square, right_square = nums[left] ** 2, nums[right] ** 2
            if left_square < right_square:
                res[idx] = right_square
                right -= 1
            else:
                res[idx] = left_square
                left += 1
            idx -= 1
        return res

        # use sorted
        # for i in range(len(nums)):
        #     nums[i] *= nums[i]
        # return sorted(nums)



s = Solution()
nums = [-4, -1, 0, 3, 10]
print(s.sortedSquares(nums))  # [0,1,9,16,100]

nums = [-7, -3, 2, 3, 11]
print(s.sortedSquares(nums))  # [4,9,9,49,121]

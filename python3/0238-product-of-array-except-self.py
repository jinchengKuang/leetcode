class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left_sum = [1] * (len(nums) + 1)
        right_sum = [1] * (len(nums) + 1)

        for i in range(1, len(left_sum)):
            left_sum[i] = left_sum[i - 1] * nums[i - 1]

        for j in range(len(right_sum) - 2, -1, -1):
            right_sum[j] = right_sum[j + 1] * nums[j]

        result = [1] * len(nums)
        for i in range(1, len(left_sum)):
            result[i - 1] = left_sum[i - 1] * right_sum[i]

        return result
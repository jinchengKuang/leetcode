class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left_preSum = [0] * (len(nums) + 1)
        right_preSum = [0] * (len(nums) + 1)

        for i in range(1, len(left_preSum)):
            left_preSum[i] = left_preSum[i - 1] + nums[i - 1]

        for j in range(len(right_preSum) - 2, -1, -1):
            right_preSum[j] = right_preSum[j + 1] + nums[j]

        for i in range(1, len(left_preSum)):
            if left_preSum[i] == right_preSum[i - 1]:
                return i - 1
        return -1

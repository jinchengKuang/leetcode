class Solution:
    def threeSum(self, nums: [int]) -> [[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i >= 1 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total > 0:
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    res.append([nums[i], nums[left], nums[right]])
                    while left != right and nums[left] == nums[left + 1]:
                        left += 1
                    while left != right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
        return res


nums = [-1, 0, 1, 2, -1, -4]
print(Solution().threeSum(nums))  # [[-1, -1, 2], [-1, 0, 1]]

nums = [0, 1, 1]
print(Solution().threeSum(nums))  # []

nums = [0, 0, 0, 0]
print(Solution().threeSum(nums))  # [[0, 0, 0]

class Solution:
    def fourSum(self, nums: [int], target: int) -> [[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums)):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                left, right = j + 1, len(nums) - 1
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    if total > target:
                        right -= 1
                    elif total < target:
                        left += 1
                    else:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        while left != right and nums[left] == nums[left + 1]:
                            left += 1
                        while left != right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
        return res


nums = [1, 0, -1, 0, -2, 2]
target = 0
print(Solution().fourSum(nums, target))  # [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

nums = [2, 2, 2, 2, 2]
target = 8
print(Solution().fourSum(nums, target))  # [[2,2,2,2]]

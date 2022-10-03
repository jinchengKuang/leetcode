class Solution:
    def twoSum(self, nums: [int], target: int) -> [int]:
        record = dict()
        for idx, val in enumerate(nums):
            if target - val not in record:
                record[val] = idx
            else:
                return [record[target - val], idx]


nums = [2, 7, 11, 15]
target = 9
print(Solution().twoSum(nums, target))  # [0,1]

nums = [3, 2, 4]
target = 6
print(Solution().twoSum(nums, target))  # [1,2]

nums = [3, 3]
target = 6
print(Solution().twoSum(nums, target))  # [0,1]

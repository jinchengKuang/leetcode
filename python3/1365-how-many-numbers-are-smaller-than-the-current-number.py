class Solution:
    def smallerNumbersThanCurrent(self, nums: [int]) -> [int]:
        res = nums[:]
        res.sort()
        hmap = {}
        for idx, num in enumerate(res):
            if num not in hmap:
                hmap[num] = idx
        for idx, num in enumerate(nums):
            res[idx] = hmap[num]
        return res


nums = [8, 1, 2, 2, 3]
print(Solution().smallerNumbersThanCurrent(nums))  # [4, 0, 1, 1, 3]

nums = [6, 5, 4, 8]
print(Solution().smallerNumbersThanCurrent(nums))  # [2, 1, 0, 3]

nums = [7, 7, 7, 7]
print(Solution().smallerNumbersThanCurrent(nums))  # [0, 0, 0, 0]

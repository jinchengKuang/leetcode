from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow = fast = 0
        while fast < len(nums):
            if nums[slow] != nums[fast]:
                slow += 1
                nums[slow] = nums[fast]
            fast += 1
        return slow + 1

    # def removeDuplicates(self, nums: List[int]) -> int:
    #     nums[:] = sorted(set(nums))
    #     return len(nums)


s = Solution()
nums = [1, 1, 2]
print(s.removeDuplicates(nums))  # 2

nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]  # 5
print(s.removeDuplicates(nums))

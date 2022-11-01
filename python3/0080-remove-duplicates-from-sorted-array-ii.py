class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow = fast = 0
        count = 0
        while fast < len(nums):
            if nums[slow] != nums[fast]:
                slow += 1
                nums[slow] = nums[fast]
            elif slow < fast and count < 2:
                slow += 1
                nums[slow] = nums[fast]
            count += 1
            fast += 1
            if fast < len(nums) and nums[fast] != nums[fast - 1]:
                count = 0
        return slow + 1

    def removeDuplicates2(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return len(nums)
        slow = fast = 2
        while fast < len(nums):
            if nums[fast] != nums[slow - 2]:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow

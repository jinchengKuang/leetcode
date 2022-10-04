class Solution:
    def fourSumCount(self, nums1: [int], nums2: [int], nums3: [int], nums4: [int]) -> int:
        record = dict()
        for i in nums1:
            for j in nums2:
                if i + j in record:
                    record[i + j] += 1
                else:
                    record[i + j] = 1
        count = 0
        for i in nums3:
            for j in nums4:
                key = - i - j
                if key in record:
                    count += record[key]
        return count


nums1 = [1, 2]
nums2 = [-2, -1]
nums3 = [-1, 2]
nums4 = [0, 2]
print(Solution().fourSumCount(nums1, nums2, nums3, nums4))  # 2

nums1 = [0]
nums2 = [0]
nums3 = [0]
nums4 = [0]
print(Solution().fourSumCount(nums1, nums2, nums3, nums4))  # 1

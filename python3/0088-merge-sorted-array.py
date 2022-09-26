class Solution:
    def merge(self, nums1: [int], m: int, nums2: [int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1, p2 = m - 1, n - 1
        cur = m + n - 1
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] > nums2[p2]:
                nums1[cur] = nums1[p1]
                p1 -= 1
            else:
                nums1[cur] = nums2[p2]
                p2 -= 1
            cur -= 1
        while p2 >= 0:
            nums1[cur] = nums2[p2]
            p2 -= 1
            cur -= 1


s = Solution()

nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3
s.merge(nums1, m, nums2, n)  # [1,2,2,3,5,6]
print(nums1)

nums1 = [1]
m = 1
nums2 = []
n = 0
s.merge(nums1, m, nums2, n)  # [1]
print(nums1)

nums1 = [0]
m = 0
nums2 = [1]
n = 1
s.merge(nums1, m, nums2, n)  # [1]
print(nums1)

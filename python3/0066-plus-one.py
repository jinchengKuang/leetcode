class Solution:
    def plusOne(self, digits: [int]) -> [int]:
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += 1
            if digits[i] != 10:
                return digits
            digits[i] = 0
        return [1] + digits


l1 = [1, 2, 3]
print(Solution().plusOne(l1))  # [1, 2, 4]

l2 = [4, 3, 2, 1]
print(Solution().plusOne(l2))  # [4, 3, 2, 2]

l3 = [9]
print(Solution().plusOne(l3))  # [1, 0]

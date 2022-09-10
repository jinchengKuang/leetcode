from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        """
        two pointers
        """
        # left, right = 0, len(numbers) - 1
        # while left <= right:
        #     total = numbers[left] + numbers[right]
        #     if total > target:
        #         right -= 1
        #     elif total < target:
        #         left += 1
        #     else:
        #         return sorted([left + 1, right + 1])

        """
        two points + binary search
        """
        for i in range(len(numbers)):
            new_target = target - numbers[i]
            left, right = i + 1, len(numbers) - 1
            while left <= right:
                mid = (left + right) // 2
                if numbers[mid] > new_target:
                    right = mid - 1
                elif numbers[mid] < new_target:
                    left = mid + 1
                else:
                    return [i + 1, mid + 1]


s = Solution()
numbers = [2, 7, 11, 15]
target = 9
print(s.twoSum(numbers, target))  # [1,2]

numbers = [2, 3, 4]
target = 6
print(s.twoSum(numbers, target))  # [1,3]

numbers = [-1, 0]
target = -1
print(s.twoSum(numbers, target))  # [1,2]

numbers = [0, 0, 3, 4]
target = 0
print(s.twoSum(numbers, target))  # [1,2]

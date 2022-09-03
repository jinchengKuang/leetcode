import math


class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x
        left, right = 1, x // 2
        while left <= right:
            mid = (left + right) // 2
            mid_square = mid * mid
            if mid_square > x:
                right = mid - 1
            elif mid_square < x:
                left = mid + 1
            else:
                return mid
        return left if left * left <= x else left - 1


s = Solution()
for i in range(50):
    if s.mySqrt(i) != math.floor(math.sqrt(i)):
        print(i, "false")

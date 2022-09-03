class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num <= 1:
            return True
        left, right = 0, num // 2
        while left <= right:
            mid = (left + right) // 2
            mid_square = mid * mid
            if mid_square < num:
                left = mid + 1
            elif mid_square > num:
                right = mid - 1
            else:
                return True
        return False


s = Solution()
num = 16
print(s.isPerfectSquare(num))

num = 14
print(s.isPerfectSquare(num))

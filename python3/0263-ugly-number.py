class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0:
            return False
        while n % 2 == 0:
            n //= 2
        while n % 3 == 0:
            n //= 3
        while n % 5 == 0:
            n //= 5
        return True if n == 1 else False

        # more pythonic way
        # if n <= 0:
        #     return False
        # for i in [2, 3, 5]:
        #     while n % i == 0:
        #         n //= i
        # return True if n == 1 else False


print(Solution().isUgly(6))  # True
print(Solution().isUgly(1))  # True
print(Solution().isUgly(14))  # False
print(Solution().isUgly(-30))  # False

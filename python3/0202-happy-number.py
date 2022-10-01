class Solution:
    def isHappy(self, n: int) -> bool:
        def get_sum(num: int):
            sum_ = 0
            while num:
                sum_ += (num % 10) ** 2
                num //= 10
            return sum_

        record = set()
        while True:
            n = get_sum(n)
            if n == 1:
                return True
            if n in record:
                return False
            else:
                record.add(n)


n = 19
print(Solution().isHappy(n))  # T

n = 2
print(Solution().isHappy(n))  # F

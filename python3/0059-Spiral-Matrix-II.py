from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]
        upper_bound = 0
        lower_bound = n - 1
        left_bound = 0
        right_bound = n - 1
        num = 1

        while num <= n * n:
            if upper_bound <= lower_bound:
                for i in range(left_bound, right_bound + 1):
                    res[upper_bound][i] = num
                    num += 1
                upper_bound += 1

            if left_bound <= right_bound:
                for i in range(upper_bound, lower_bound + 1):
                    res[i][right_bound] = num
                    num += 1
                right_bound -= 1

            if upper_bound <= lower_bound:
                for i in range(right_bound, left_bound - 1, -1):
                    res[lower_bound][i] = num
                    num += 1
                lower_bound -= 1

            if left_bound <= right_bound:
                for i in range(lower_bound, upper_bound - 1, -1):
                    res[i][left_bound] = num
                    num += 1
                left_bound += 1

        return res


s = Solution()
print(s.generateMatrix(3))  # [[1,2,3],[8,9,4],[7,6,5]]

print(s.generateMatrix(1))  # [[1]]

from typing import List


class Solution:
    # def totalFruit(self, fruits: List[int]) -> int:
    #     picked = {}
    #     res = 0
    #     start = 0
    #     for end in range(len(fruits)):
    #         picked[fruits[end]] = end
    #         if len(picked) > 2:
    #             min_val = min(picked.values())
    #             start = min_val + 1
    #             del picked[fruits[min_val]]
    #         res = max(res, end - start + 1)
    #     return res

    def totalFruit(self, fruits: List[int]) -> int:
        picked = {}
        num_baskets = 2
        left = 0
        for right in range(len(fruits)):
            if fruits[right] not in picked:
                num_baskets -= 1
                picked[fruits[right]] = 1
            else:
                picked[fruits[right]] += 1

            if num_baskets < 0:
                if picked[fruits[left]] == 1:
                    del picked[fruits[left]]
                    num_baskets += 1
                else:
                    picked[fruits[left]] -= 1
                left += 1
        return right - left + 1


s = Solution()
fruits = [1, 2, 1]
print(s.totalFruit(fruits))  # 3

fruits = [0, 1, 2, 2]
print(s.totalFruit(fruits))  # 3

fruits = [1, 2, 3, 2, 2]
print(s.totalFruit(fruits))  # 4

class Solution:
    def calPoints(self, operations: [str]) -> int:
        stk = []
        for i in operations:
            if i == "+":
                stk.append(stk[-1] + stk[-2])
            elif i == "D":
                stk.append(stk[-1] * 2)
            elif i == "C":
                stk.pop()
            else:
                stk.append(int(i))
        return sum(stk)


ops = ["5", "2", "C", "D", "+"]
print(Solution().calPoints(ops))

ops = ["5", "-2", "4", "C", "D", "9", "+", "+"]
print(Solution().calPoints(ops))

ops = ["1", "C"]
print(Solution().calPoints(ops))

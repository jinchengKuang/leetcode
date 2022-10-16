class Solution:
    def evalRPN(self, tokens: [str]) -> int:
        stk = []
        for i in tokens:
            if i not in ["+", "-", "*", "/"]:
                stk.append(i)
            else:
                if i == "+":
                    x, y = int(stk.pop()), int(stk.pop())
                    stk.append(y + x)
                elif i == "-":
                    x, y = int(stk.pop()), int(stk.pop())
                    stk.append(y - x)
                elif i == "*":
                    x, y = int(stk.pop()), int(stk.pop())
                    stk.append(y * x)
                elif i == "/":
                    x, y = int(stk.pop()), int(stk.pop())
                    stk.append(y / x)
        return stk.pop()


tokens = ["2", "1", "+", "3", "*"]
print(Solution().evalRPN(tokens))  # 9

tokens = ["4", "13", "5", "/", "+"]
print(Solution().evalRPN(tokens))  # 6

tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
print(Solution().evalRPN(tokens))  # 22

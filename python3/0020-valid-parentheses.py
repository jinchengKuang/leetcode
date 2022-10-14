class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for i in s:
            if i == '(':
                stk.append(')')
            elif i == '[':
                stk.append(']')
            elif i == '{':
                stk.append('}')
            elif stk and i == stk[-1]:
                stk.pop()
            else:
                return False
        return False if stk else True


s = "()"
print(Solution().isValid(s))  # True

s = "()[]{}"
print(Solution().isValid(s))  # True

s = "(]"
print(Solution().isValid(s))  # False

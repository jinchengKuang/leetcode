from typing import List


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def getResult(s: str) -> List[str]:
            stack = []
            for ch in s:
                if ch != "#":
                    stack.append(ch)
                elif ch == "#" and stack:
                    stack.pop()
            return stack

        return getResult(s) == getResult(t)


slt = Solution()
s = "ab#c"
t = "ad#c"
print(slt.backspaceCompare(s, t))

s = "ab##"
t = "c#d#"
print(slt.backspaceCompare(s, t))

s = "a#c"
t = "b"
print(slt.backspaceCompare(s, t))

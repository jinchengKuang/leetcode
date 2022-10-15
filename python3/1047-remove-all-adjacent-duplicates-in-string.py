class Solution:
    def removeDuplicates(self, s: str) -> str:
        stk = []
        for i in s:
            if stk:
                if stk[-1] == i:
                    stk.pop()
                else:
                    stk.append(i)
            else:
                stk.append(i)
        return ''.join(stk)

        # stk = []
        # for i in s:
        #     if stk and stk[-1] == i:
        #         stk.pop()
        #     else:
        #         stk.append(i)
        # return ''.join(stk)


s = 'abbaca'
print(Solution().removeDuplicates(s))
s = 'azxxzy'
print(Solution().removeDuplicates(s))

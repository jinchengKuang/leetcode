class Solution:
    def getRow(self, rowIndex: int) -> [int]:
        cur_row = [1]
        if rowIndex == 0:
            return cur_row
        prev_row = self.getRow(rowIndex - 1)
        for i in range(len(prev_row) - 1):
            cur_row.append(prev_row[i] + prev_row[i + 1])
        cur_row.append(1)
        return cur_row


s = Solution()
rowIndex = 3
print(s.getRow(rowIndex))  # [1,3,3,1]

rowIndex = 0
print(s.getRow(rowIndex))  # [1]

rowIndex = 1
print(s.getRow(rowIndex))  # [1,1]

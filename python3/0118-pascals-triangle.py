class Solution:
    def generate_cur_row(self, prev_row: [int]) -> [int]:
        cur_row = [1]
        for i in range(len(prev_row) - 1):
            cur_row.append(prev_row[i] + prev_row[i + 1])
        cur_row.append(1)
        return cur_row

    def generate(self, numRows: int) -> [[int]]:
        res = []
        prev_row = [1]
        res.append(prev_row)
        for row in range(2, numRows + 1):
            prev_row = res[-1]
            res.append(self.generate_cur_row(prev_row))
        return res


s = Solution()
numRows = 5
print(s.generate(numRows))  # [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

numRows = 1
print(s.generate(numRows))  # [[1]]

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]

        if numRows == 2:
            return [[1], [1, 1]]

        ans = [[1], [1, 1]]
        for i in range(numRows - 2):
            curr = [1] * (len(ans[-1]) + 1)
            for j in range(1, len(ans[-1])):
                curr[j] = ans[-1][j - 1] + ans[-1][j]
            ans.append(curr)
        
        return ans
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows <= 2:
            return [[1]] if numRows == 1 else [[1], [1,1]]
        
        dp = [[1], [1, 1]]
        for i in range(3, numRows + 1):
            curr = [1] * i
            for j in range(1, i - 1):
                curr[j] = dp[i - 2][j - 1] + dp[i - 2][j]
            dp.append(curr)
        return dp
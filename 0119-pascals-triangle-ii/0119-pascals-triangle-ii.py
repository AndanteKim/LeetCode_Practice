class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex <= 1:
            if rowIndex == 0:
                return [1]
            return [1, 1]
        
        prev_dp, dp = [1, 1], [1]
        
        for num in range(2, rowIndex + 1):
            dp = [1] * (num + 1)
            for i in range(1, num):
                dp[i] = prev_dp[i - 1] + prev_dp[i]
            prev_dp = dp
            
        return dp
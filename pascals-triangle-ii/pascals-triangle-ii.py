class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # Base case
        if rowIndex == 0:
            return [1]
        
        if rowIndex == 1:
            return [1, 1]
        
        # Space optimized dp
        prev_dp = [1, 1]
        for n in range(2, rowIndex + 1):
            dp = [0] * (n + 1)
            dp[0] = 1
            for i in range(1, n):
                dp[i] = prev_dp[i - 1] + prev_dp[i]
            dp[-1] = 1
            prev_dp = dp
        
        return prev_dp
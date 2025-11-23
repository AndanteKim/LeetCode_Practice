class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        def dp(i: int, j: int, sum_: int) -> int:
            if i == n:
                return sum_ if sum_ % 3 == 0 else 0

            if memo[i][j] != -1:
                return memo[i][j]
            
            memo[i][j] = max(dp(i + 1, (j + nums[i]) % 3, nums[i] + sum_), dp(i + 1, j, sum_))
            return memo[i][j]
        
        n = len(nums)
        memo = [[-1] * 3 for _ in range(n)]
        return dp(0, 0, 0)
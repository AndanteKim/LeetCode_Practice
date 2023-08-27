class Solution:
    def canCross(self, stones: List[int]) -> bool:
        mark, dp = defaultdict(int), [[0] * 2001 for _ in range(2001)]
        n = len(stones)
        
        for i in range(n):
            mark[stones[i]] = i
        
        dp[0][0] = 1
        for index in range(n):
            for prev_jump in range(n + 1):
                if dp[index][prev_jump]:
                    if mark[stones[index] + prev_jump]:
                        dp[mark[stones[index] + prev_jump]][prev_jump] = 1
                    if mark[stones[index] + prev_jump + 1]:
                        dp[mark[stones[index] + prev_jump + 1]][prev_jump + 1] = 1
                    if mark[stones[index] + prev_jump - 1]:
                        dp[mark[stones[index] + prev_jump - 1]][prev_jump - 1] = 1
        
        for prev_jump in range(n + 1):
            if dp[n - 1][prev_jump]:
                return True
        return False
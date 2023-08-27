class Solution:
    def solve(self, stones: List[int], n: int, index: int, prev_jump: int, dp: List[List[int]], mark: Dict[int, int]) -> int:
        if index == n - 1:
            return 1
        
        if dp[index][prev_jump] != -1:
            return dp[index][prev_jump]

        ans = False
        for next_jump in range(prev_jump - 1, prev_jump + 2):
            if next_jump > 0 and stones[index] + next_jump in mark:
                ans = ans or self.solve(stones, n, mark[stones[index] + next_jump], next_jump, dp, mark)
        
        dp[index][prev_jump] = ans
        return ans
        
    def canCross(self, stones: List[int]) -> bool:
        dp = [[-1] * 2001 for _ in range(2001)]
        mark = dict()
        
        for i in range(len(stones)):
            mark[stones[i]] = i
        
        return self.solve(stones, len(stones), 0, 0, dp, mark)
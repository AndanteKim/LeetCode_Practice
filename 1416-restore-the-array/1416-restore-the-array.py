class Solution:
    def dfs(self, start: int, s: str, m: int, n: int, k: int, dp: List[int], mod: int) -> int:
        if dp[start]:
            return dp[start]
        
        if start == m:
            return 1
        
        if s[start] == '0':
            return 0
        
        count = 0
        for end in range(start, m):
            curr_number = s[start: end + 1]
            if int(curr_number) > k:
                break
            count += self.dfs(end + 1, s, m, n, k, dp, mod)
        dp[start] = count % mod
        return count
    
    def numberOfArrays(self, s: str, k: int) -> int:
        m, n = len(s), len(str(k))
        mod = 10 ** 9 + 7
        dp = [0] * (m + 1)
        
        return self.dfs(0, s, m, n, k, dp, mod) % mod
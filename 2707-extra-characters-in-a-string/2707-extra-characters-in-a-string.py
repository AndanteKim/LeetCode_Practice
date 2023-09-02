class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n, dict_set = len(s), set(dictionary)
        dp = [0] * (len(s) + 1)
        
        for start in range(n - 1, -1, -1):
            dp[start] = 1 + dp[start + 1]
            for end in range(start, n):
                curr = s[start: end + 1]
                if curr in dict_set:
                    dp[start] = min(dp[start], dp[end + 1])
        
        return dp[0]
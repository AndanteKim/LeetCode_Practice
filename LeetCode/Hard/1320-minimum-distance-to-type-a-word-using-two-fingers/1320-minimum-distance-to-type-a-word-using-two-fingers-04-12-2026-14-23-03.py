class Solution:
    def minimumDistance(self, word: str) -> int:
        def get_dist(p: int, q: int) -> int:
            x1, y1 = p // 6, p % 6
            x2, y2 = q // 6, q % 6
            return abs(x1 - x2) + abs(y1 - y2)
        
        n = len(word)
        dp = [[[float('inf')] * 26 for x in range(26)] for y in range(n)]

        for i in range(26):
            dp[0][i][ord(word[0]) - 65] = 0
            dp[0][ord(word[0]) - 65][i] = 0
        
        for i in range(1, n):
            curr, prev = ord(word[i]) - 65, ord(word[i - 1]) - 65
            d = get_dist(prev, curr)

            for j in range(26):
                dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][prev][j] + d)
                dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][j][prev] + d)

                if prev == j:
                    for k in range(26):
                        d0 = get_dist(k, curr)
                        dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][k][j] + d0)
                        dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][j][k] + d0)

        ans = min(min(dp[n - 1][x]) for x in range(26))
        return ans

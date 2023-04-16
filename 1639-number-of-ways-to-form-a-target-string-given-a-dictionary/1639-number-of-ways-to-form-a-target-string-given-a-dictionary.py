class Solution:
    def f(self, i: int, j: int, target: str, mod: int) -> int:
        if j == 0:
            return 1 if i == 0 else 0
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        self.dp[i][j] = self.f(i, j - 1, target, mod)
        if i > 0:
            self.dp[i][j] += (self.cnt[ord(target[i - 1]) - ord('a')][j - 1] * self.f(i - 1, j - 1, target, mod))
        self.dp[i][j] %= mod
        return self.dp[i][j]
    
    def numWays(self, words: List[str], target: str) -> int:
        alphabet = 26
        mod = int(1e9 +7)
        m, k = len(target), len(words[0])
        self.cnt = [[0] * k for _ in range(alphabet)]
        for j in range(k):
            for word in words:
                self.cnt[ord(word[j]) - ord('a')][j] += 1
        self.dp = [[-1] * (k + 1) for _ in range(m + 1)]
        return self.f(m, k, target, mod)
        
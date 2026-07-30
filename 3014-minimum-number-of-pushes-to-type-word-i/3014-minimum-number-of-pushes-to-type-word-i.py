class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        m = (n - 1) // 8 + 1
        return m * (m - 1) * 4 + (n - (m - 1) * 8) * m
class Solution:
    def maxOperations(self, s: str) -> int:
        n = len(s)
        ans, ones = 0, 0

        for i in range(n):
            if s[i] == '1':
                ones += 1
            elif i + 1 == n or s[i + 1] == '1':
                ans += ones

        return ans
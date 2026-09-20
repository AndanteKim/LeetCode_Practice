class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0

        for i, c in enumerate(s):
            ans += (123 - ord(c)) * (i + 1)

        return ans
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, k = len(strs), len(strs[0])
        ans = 0

        for c in range(k):
            for r in range(1, n):
                if strs[r - 1][c] > strs[r][c]:
                    ans += 1
                    break

        return ans
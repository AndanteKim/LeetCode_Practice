class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        ans = grid[:]
        i0, i1 = x, x + k - 1

        while i0 < i1:
            for j in range(y, y + k):
                ans[i0][j], ans[i1][j] = ans[i1][j], ans[i0][j]
            i0, i1 = i0 + 1, i1 - 1

        return ans
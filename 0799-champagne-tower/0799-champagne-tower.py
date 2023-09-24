class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        ans = [[0] * k for k in range(1, 102)]
        ans[0][0] = poured
        for r in range(query_row + 1):
            for c in range(r + 1):
                quotient = (ans[r][c] - 1.0) / 2.0
                if quotient > 0:
                    ans[r + 1][c] += quotient
                    ans[r + 1][c + 1] += quotient
                
        return min(1, ans[query_row][query_glass])
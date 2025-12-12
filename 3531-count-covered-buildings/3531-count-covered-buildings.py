class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        max_row, min_row = [0] * (n + 1), [n + 1] * (n + 1)
        max_col, min_col = [0] * (n + 1), [n + 1] * (n + 1)

        for x, y in buildings:
            max_row[y] = max(max_row[y], x)
            min_row[y] = min(min_row[y], x)
            max_col[x] = max(max_col[x], y)
            min_col[x] = min(min_col[x], y)

        ans = 0
        for x, y in buildings:
            if min_row[y] < x and x < max_row[y] and\
            min_col[x] < y and y < max_col[x]:
                ans += 1

        return ans

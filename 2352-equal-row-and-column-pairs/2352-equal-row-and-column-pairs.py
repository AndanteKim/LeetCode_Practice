class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        rows, cols = dict(), dict()
        m, n = len(grid), len(grid[0])
        
        for i in range(m):
            rows[tuple(grid[i])] = rows.get(tuple(grid[i]), 0) + 1
        for i in range(n):
            curr = []
            for j in range(m):
                curr.append(grid[j][i])
            cols[tuple(curr[:])] = cols.get(tuple(curr[:]), 0) + 1
        
        ans = 0
        for row, freq in rows.items():
            if row in cols:
                ans += freq * cols[row]
                
        return ans
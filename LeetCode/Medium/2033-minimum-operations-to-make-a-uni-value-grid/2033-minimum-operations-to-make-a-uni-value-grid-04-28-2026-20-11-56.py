class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        m, n, elems = len(grid), len(grid[0]), []

        for i in range(m):
            for j in range(n):
                elems.append(grid[i][j])
        
        elems.sort()

        ans, avg = 0, elems[(m * n) // 2 - 1] if (m * n) % 2 == 0 else elems[(m * n) >> 1]

        for i in range(m):
            for j in range(n):
                if abs(avg - grid[i][j]) % x != 0:
                    return -1

                ans += abs(avg - grid[i][j]) // x

        return ans
class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        ans, prefix = 0, [[[0, 0] for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'X':
                    prefix[i + 1][j + 1][0] = prefix[i + 1][j][0] + prefix[i][j + 1][0] - prefix[i][j][0] + 1
                    prefix[i + 1][j + 1][1] = 1
                elif grid[i][j] == 'Y':
                    prefix[i + 1][j + 1][0] = prefix[i + 1][j][0] + prefix[i][j + 1][0] - prefix[i][j][0] - 1
                    prefix[i + 1][j + 1][1] = prefix[i + 1][j][1] | prefix[i][j + 1][1]
                else:
                    prefix[i + 1][j + 1][0] = prefix[i + 1][j][0] + prefix[i][j + 1][0] - prefix[i][j][0]
                    prefix[i + 1][j + 1][1] = prefix[i + 1][j][1] | prefix[i][j + 1][1]

                if prefix[i + 1][j + 1][0] == 0 and prefix[i + 1][j + 1][1] == 1:
                    ans += 1
        
        return ans
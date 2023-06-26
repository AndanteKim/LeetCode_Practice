class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        IO, EO, DI, DE = 120, 40, -30, 20
        fine = [[0, 0, 0], [0, 2 * DI, DI + DE], [0, DI + DE, 2 * DE]]
        
        @lru_cache(None)
        def dp(index: int, row: int, I: int, E: int) -> int:
            if index == -1:
                return 0
            R, C, ans = index // n, index % n, []
            neighbors = [(1, I - 1, E, IO), (2, I, E - 1, EO), (0, I, E, 0)]
            
            for val, dx, dy, gain in neighbors:
                tmp = 0
                if dx >= 0 and dy >= 0:
                    tmp = dp(index - 1, (val, ) + row[:-1], dx, dy) + gain
                    if C < n - 1:
                        tmp += fine[val][row[0]]
                    if R < m - 1:
                        tmp += fine[val][row[-1]]
                ans.append(tmp)
            
            return max(ans)
        
        if m < n:
            m, n = n, m
        return dp(m * n - 1, tuple([0] * n), introvertsCount, extrovertsCount)
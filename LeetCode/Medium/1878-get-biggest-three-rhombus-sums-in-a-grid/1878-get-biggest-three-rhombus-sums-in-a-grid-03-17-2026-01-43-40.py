class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        sums = set()

        for i in range(m):
            for j in range(n):
                # Size 0 rhombus (single cell)
                sums.add(grid[i][j])

                k = 1
                while True:
                    r = i + 2 * k
                    left, right = j - k, j + k

                    if r >= m or left < 0 or right >= n:
                        break

                    total, x, y = 0, i, j

                    # Top -> Right
                    for t in range(k):
                        total += grid[x + t][y + t]
                    
                    # Right -> bottom:
                    for t in range(k):
                        total += grid[x + k + t][y + k - t]
                    
                    # Bottom -> Left
                    for t in range(k):
                        total += grid[x + 2 * k - t][y - t]
                    
                    # Left -> Top
                    for t in range(k):
                        total += grid[x + k - t][y - k + t]
                    
                    sums.add(total)
                    k += 1

        return sorted(sums, reverse = True)[:3]
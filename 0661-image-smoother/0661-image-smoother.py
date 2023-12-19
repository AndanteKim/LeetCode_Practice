class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        directions = ((0, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0))
        m, n = len(img), len(img[0])
        filtered = [[0] * n for _ in range(m)]
        
        for y in range(m):
            for x in range(n):
                total, cells = 0, 0
                for dx, dy in directions:
                    if 0 <= y + dy < m and 0 <= x + dx < n:
                        total += img[y + dy][x + dx]
                        cells += 1
                filtered[y][x] = total // cells
        return filtered
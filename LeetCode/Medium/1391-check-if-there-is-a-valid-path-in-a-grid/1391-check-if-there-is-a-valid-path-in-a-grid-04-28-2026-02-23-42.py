class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        def not_valid(r: int, c: int) -> bool:
            return r < 0 or r >= m or c < 0 or c >= n or visited[r][c]
        
        m, n = len(grid), len(grid[0])
        dirs = {
            1: ((0, -1), (0, 1)),
            2: ((-1, 0), (1, 0)),
            3: ((0, -1), (1, 0)),
            4: ((0, 1), (1, 0)),
            5: ((0, -1), (-1, 0)),
            6: ((0, 1), (-1, 0))
        }

        visited = [[False] * n for _ in range(m)]
        q = deque([(0, 0)])
        visited[0][0] = True

        while q:
            r, c = q.popleft()

            if r == m - 1 and c == n - 1:
                return True

            for dr, dc in dirs[grid[r][c]]:
                new_r, new_c = r + dr, c + dc

                if not_valid(new_r, new_c):
                    continue

                for back_dr, back_dc in dirs[grid[new_r][new_c]]:
                    if new_r + back_dr == r and new_c + back_dc == c:
                        visited[new_r][new_c] = True
                        q.append((new_r, new_c))

        return False
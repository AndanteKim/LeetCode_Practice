class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])
        id = [[0] * n for _ in range(m)]
        sx = sy = 0
        cnt = 0
        for i in range(m):
            for j in range(n):
                if classroom[i][j] == 'S':
                    sx, sy = i, j

                if classroom[i][j] == 'L':
                    id[i][j] = 1 << cnt
                    cnt += 1

        full = 1 << cnt
        best_e = [[[-1 for _ in range(full)] for _ in range(n)] for _ in range(m)]
        
        info = deque()
        info.append((sx, sy, 0, energy, 0))

        while info:
            x, y, mask, e, steps = info.popleft()

            if mask == full - 1:
                return steps
            
            if e == 0:
                continue
            
            for new_x, new_y in (x - 1, y), (x + 1 , y), (x, y - 1), (x, y + 1):
                if new_x < 0 or new_x >= m or new_y < 0 or new_y >= n or classroom[new_x][new_y] == 'X':
                    continue

                new_e = energy if classroom[new_x][new_y] == 'R' else e - 1
                new_mask = mask | id[new_x][new_y]

                if new_e > best_e[new_x][new_y][new_mask]:
                    best_e[new_x][new_y][new_mask] = new_e
                    info.append((new_x, new_y, new_mask, new_e, steps + 1))
        
        return -1

        

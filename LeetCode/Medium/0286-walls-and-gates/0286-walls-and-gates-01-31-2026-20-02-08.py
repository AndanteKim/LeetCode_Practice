class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m, n, inf = len(rooms), len(rooms[0]), 2 ** 31 - 1
        q = deque()

        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    q.append((i, j))

        while q:
            x, y = q.popleft()

            for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                new_x, new_y = x + dx, y + dy

                if new_x < 0 or new_x >= m or new_y < 0 or new_y >= n or rooms[new_x][new_y] != inf:
                    continue
                
                rooms[new_x][new_y] = rooms[x][y] + 1
                q.append((new_x, new_y))
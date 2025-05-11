class State:
    def __init__(self, x: int, y: int, dis: int):
        self.x, self.y, self.dis = x, y, dis

    def __lt__(self, other: 'State'):
        return self.dis < other.dis

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n, m = len(moveTime), len(moveTime[0])
        d = [[float('inf')] * m for _ in range(n)]
        v = [[0] * m for _ in range(n)]
        d[0][0], q = 0, []
        heappush(q, State(0, 0, 0))

        while q:
            s = heappop(q)
            if v[s.x][s.y]:
                continue
            
            if s.x == n - 1 and s.y == m - 1:
                break
            
            v[s.x][s.y] = 1

            for dx, dy in ((1, 0), (-1, 0), (0, -1), (0, 1)):
                nx, ny = s.x + dx, s.y + dy
                if not (0 <= nx < n and 0 <= ny < m):
                    continue
                dist = max(d[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y) % 2 + 1

                if d[nx][ny] > dist:
                    d[nx][ny] = dist
                    heappush(q, State(nx, ny, dist))

        return d[n - 1][m - 1]
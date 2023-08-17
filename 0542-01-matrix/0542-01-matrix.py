class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        ans, queue = [[0] * n for _ in range(m)], deque([])
        visited = [[False] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if not mat[i][j]:
                    queue.append((i, j, 1))
                    visited[i][j] = True
        
        while queue:
            x, y, dist = queue.popleft()
            
            for new_x, new_y in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                if 0 <= new_x < m and 0 <= new_y < n and not visited[new_x][new_y]:
                    queue.append((new_x, new_y, dist + 1))
                    ans[new_x][new_y] = dist
                    visited[new_x][new_y] = True
                        
        return ans
        
        
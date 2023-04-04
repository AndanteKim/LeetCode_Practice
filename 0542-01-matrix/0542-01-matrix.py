class Solution:
    def valid(self, x: int, y: int, mat: List[List[int]]) -> bool:
        return 0 <= x < self.rows and 0 <= y < self.cols and mat[x][y]
    
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        self.rows, self.cols = len(mat), len(mat[0])
        visited = [[False] * self.cols for _ in range(self.rows)]
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))
        queue = deque()
        
        for row in range(self.rows):
            for col in range(self.cols):
                if not mat[row][col]:
                    queue.append((row, col, 1))
                    visited[row][col] = True
        
        while queue:
            x, y, dist = queue.popleft()
            
            for dx, dy in directions:
                next_row, next_col = x + dx, y + dy
                if self.valid(next_row, next_col, mat) and not visited[next_row][next_col]:
                    visited[next_row][next_col] = True
                    queue.append((next_row, next_col, dist + 1))
                    mat[next_row][next_col] = dist
                    
        return mat
                
                    
        
        
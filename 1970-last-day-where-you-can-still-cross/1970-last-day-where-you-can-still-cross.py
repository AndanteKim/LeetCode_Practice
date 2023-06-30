class Solution:
    def valid(self, row: int, col: int, visited: List[List[bool]], status: List[List[int]]) -> bool:
        return 0 <= row < self.row and 0 <= col < self.col and not visited[row][col] and not status[row][col]
    
    def isAvailable(self, days: int, status: List[List[int]], cells: List[List[int]]) -> bool:
        for i in range(days):
            status[cells[i][0] - 1][cells[i][1] - 1] = 1
        
        visited = [[False] * self.col for _ in range(self.row)]
        queue = deque([])
        for i in range(self.col):
            if status[0][i] == 0:
                queue.append((0, i))
        
        while queue:
            r, c = queue.popleft()
            if r == self.row - 1:
                return True
            
            for nr, nc in (r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1):
                if self.valid(nr, nc, visited, status):
                    visited[nr][nc] = True
                    queue.append((nr, nc))
        
        return False
    
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        self.row, self.col = row, col
        left, right = 0, row * col
    
        while left < right:
            mid = (left + right) >> 1
            status = [[0] * col for _ in range(row)]
            if self.isAvailable(mid, status, cells):
                left = mid + 1
            else:
                right = mid
            
        return left - 1
            
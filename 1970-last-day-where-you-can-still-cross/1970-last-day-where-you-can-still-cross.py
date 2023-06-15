class Solution:
    def valid(self, x: int, y: int, visited: List[List[bool]]) -> bool:
        return 0 <= x < self.r and 0 <= y < self.c and not visited[x][y]
    
    def possible(self, days: int, cells: List[List[int]]) -> bool:
        visited = [[False] * self.c for _ in range(self.r)]
        for i in range(days + 1):
            visited[cells[i][0] - 1][cells[i][1] - 1] = True
        
        queue = deque()
        for i in range(self.c):
            if not visited[0][i]:
                queue.append((0, i))
        
        while queue:
            x, y = queue.popleft()
            if x == self.r - 1:
                return True
            for new_x, new_y in (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1):
                if self.valid(new_x, new_y, visited):
                    visited[new_x][new_y] = True
                    queue.append((new_x, new_y))
        
        return False
        
    
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        self.r, self.c = row, col
        left, right = 0, len(cells)
        
        while left < right:
            mid = (left + right) >> 1
            
            if self.possible(mid, cells):
                left = mid + 1
            else:
                right = mid
                
        return left
class Solution:
    def is_possible(self, threshold: int, heights: List[List[int]]) -> bool:
        queue = deque([(0, 0)])
        visited = [[False] * self.n for _ in range(self.m)]
        visited[0][0] = True
        while queue:
            x, y = queue.popleft()
            
            if x == self.m - 1 and y == self.n - 1:
                return True
            
            for dx, dy in (1, 0), (-1, 0), (0, 1), (0, -1):
                new_x, new_y = x + dx, y + dy
                if 0 <= new_x < self.m and 0 <= new_y < self.n and not visited[new_x][new_y] and abs(heights[new_x][new_y] - heights[x][y]) <= threshold:
                    visited[new_x][new_y] = True
                    queue.append((new_x, new_y))
            
        return False
    
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        self.m, self.n = len(heights), len(heights[0])
        
        left, right = 0, max(max(row) for row in heights)
        
        while left <= right:
            mid = (left + right) >> 1
            
            if self.is_possible(mid, heights):
                right = mid - 1
            else:
                left = mid + 1
        
        return left
class Solution:
    directions = [
            (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)
        ]
    
    def best_case_estimate(self, x: int, y: int) -> int:
        return max(self.max_row - x, self.max_col - y)
    
    def get_neighbours(self, x: int, y: int) -> Tuple[int, int]:
        for dx, dy in self.directions:
            new_x, new_y = x + dx, y + dy
            if not (0 <= new_x <= self.max_row and 0 <= new_y <= self.max_col):
                continue
            if self.grid[new_x][new_y] == 1:
                continue
            yield (new_x, new_y)
            
            
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        self.max_row, self.max_col, self.grid = len(grid) - 1, len(grid[0]) - 1, grid
        if grid[0][0] or grid[self.max_row][self.max_col]:
            return -1
        visited = set()
        priority_queue = [(1 + self.best_case_estimate(0, 0), 1, (0, 0))]
        
        while priority_queue:
            estimate, distance, cell = heapq.heappop(priority_queue)
            if cell in visited:
                continue
            if cell == (self.max_row, self.max_col):
                return distance
            visited.add(cell)
            for neighbor in self.get_neighbours(*cell):
                if neighbor in visited:
                    continue
                estimate = self.best_case_estimate(*neighbor) + distance + 1
                entry = (estimate, distance + 1, neighbor)
                heapq.heappush(priority_queue, entry)
        return -1
        
        
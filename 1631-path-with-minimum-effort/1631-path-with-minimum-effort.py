class Solution:
    def valid(self, x: int, y: int) -> bool:
        return 0 <= x < self.r and 0 <= y < self.c
    
    def dfs(self, k: int, heights: List[List[int]]) -> bool:
        directions = ((1, 0), (-1, 0), (0, -1), (0, 1))
        stack = [(0, 0)]
        visited = [[False] * self.c for _ in range(self.r)]
        
        while stack:
            row, col = stack.pop()
            if row == self.r - 1 and col == self.c - 1:
                return True
            
            for dr, dc in directions:
                new_r, new_c = row + dr, col + dc
                if self.valid(new_r, new_c) and not visited[new_r][new_c]:
                    if (abs(heights[new_r][new_c] - heights[row][col]) <= k):
                        visited[new_r][new_c] = True
                        stack.append((new_r, new_c))
                        
        return False
    
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        self.r, self.c = len(heights), len(heights[0])
        left, right = 0, max(max(row) for row in heights)
        
        while left <= right:
            mid = (left + right) // 2
            if (self.dfs(mid, heights)):
                right = mid - 1
            else:
                left = mid + 1
        
        return left
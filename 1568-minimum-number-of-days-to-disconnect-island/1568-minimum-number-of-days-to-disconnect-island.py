class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        def _count_islands() -> int:
            visited, count = set(), 0
            
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1 and (i, j) not in visited:
                        _explore_island(i, j, visited)
                        count += 1
                        
            return count
        
        def _explore_island(i: int, j: int, visited: Set[Tuple[int]]) -> None:
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0 or (i, j) in visited:
                return
            
            visited.add((i, j))
            
            for di, dj in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                _explore_island(i + di, j + dj, visited)
                
        m, n = len(grid), len(grid[0])
        
        # Base case: Check if already disconnected
        if _count_islands() != 1:
            return 0
        
        # Check if can be disconnected in 1 day
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if _count_islands() != 1:
                        return 1
                    
                    grid[i][j] = 1
                
        # If can't be disconnected in 0 or 1 day, return 2
        return 2
        
        
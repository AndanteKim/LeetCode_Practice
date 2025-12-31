class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        def is_valid(r: int, c: int, visited: List[List[bool]]) -> bool:
            return 0 <= r < row and 0 <= c < col and not visited[r][c]
        
        def available(days: int) -> bool:
            visited = [[False] * col for _ in range(row)]
            grid = [[0] * col for _ in range(row)]
            
            for day in range(days):
                r, c = cells[day]
                grid[r - 1][c - 1] = 1

            queue = deque((0, c) for c in range(col) if grid[0][c] == 0)

            while queue:
                r, c = queue.popleft()

                if visited[r][c] or grid[r][c] == 1:
                    continue
                
                visited[r][c] = True

                # If it's available to reach
                if r == row - 1:
                    return True

                for dr, dc in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                    new_r, new_c = r + dr, c + dc
                    if is_valid(new_r, new_c, visited):
                        queue.append((new_r, new_c))

            # Fail to reach
            return False
        
        left, right, ans = 0, len(cells) - 1, 0

        # Start flooding
        while left <= right:
            mid = left + ((right - left) >> 1)
            
            if available(mid):
                left = mid + 1
            else:
                right = mid - 1
        
        return right
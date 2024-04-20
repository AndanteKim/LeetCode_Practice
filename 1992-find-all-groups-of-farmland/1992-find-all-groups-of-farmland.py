class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        def is_valid(i: int, j: int) -> bool:
            return 0 <= i < rows and 0 <= j < cols and land[i][j] == 1
        
        rows, cols = len(land), len(land[0])
        starts = []
        
        for r in range(rows):
            for c in range(cols):
                if land[r][c] == 1:
                    starts.append((r,c))
        
        ans, visited = [], [[False] * cols for _ in range(rows)]
        
        for r, c in starts:
            if not visited[r][c]:
                queue = deque([(r, c)])
                curr, end_x, end_y = [r, c], r, c
                while queue:
                    x, y = queue.popleft()
                    if not visited[x][y]:
                        if x > end_x or y > end_y:
                            end_x, end_y = x, y
                        visited[x][y] = True
                        
                        for next_x, next_y in (x + 1, y), (x - 1, y), (x, y - 1), (x, y + 1):
                            if is_valid(next_x, next_y):
                                queue.append((next_x, next_y))
                curr.extend([end_x, end_y])
                ans.append(curr)
        
        return ans
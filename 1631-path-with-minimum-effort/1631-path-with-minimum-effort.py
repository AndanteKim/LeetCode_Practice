class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row, col = len(heights), len(heights[0])
        diff_mat = [[float('inf')] * col for _ in range(row)]
        diff_mat[0][0] = 0
        visited = [[False] * col for _ in range(row)]
        
        queue = [(0, 0, 0)]
        while queue:
            diff, r, c = heappop(queue)
            visited[r][c] = True
            for dr, dc in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                new_r = r + dr
                new_c = c + dc
                if 0 <= new_r < row and 0 <= new_c < col and not visited[new_r][new_c]:
                    curr_diff = abs(heights[new_r][new_c] - heights[r][c])
                    max_diff = max(curr_diff, diff_mat[r][c])
                    
                    if diff_mat[new_r][new_c] > max_diff:
                        diff_mat[new_r][new_c] = max_diff
                        heappush(queue, (max_diff, new_r, new_c))
        return diff_mat[-1][-1]
        
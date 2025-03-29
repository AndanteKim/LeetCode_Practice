class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m, n = len(grid), len(grid[0])
        ans = [0] * len(queries)

        # Directions for movement (right, down, left, up)
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        # Store queries along with their origial indices to restore order later
        sorted_queries = sorted([(val, idx) for idx, val in enumerate(queries)])

        # Min-heap (priority queue) to process cells in increasing order of value
        min_heap = [(grid[0][0], 0, 0)]
        visited = [[False] * n for _ in range(m)]

        # Keep track of the number of cells processed
        total_pts = 0
        # Start from the top-left cell
        visited[0][0] = True

        # Process queries in sorted order
        for val, idx in sorted_queries:
            # Expand the cells that are smaller than the current query value
            while min_heap and min_heap[0][0] < val:
                curr_val, curr_r, curr_c = heappop(min_heap)

                # Increment count of valid cells
                total_pts += 1

                # Explore all four possible directions
                for dr, dc in dirs:
                    new_r, new_c = curr_r + dr, curr_c + dc

                    # Check if the new cell is within bounds and not visited
                    if (new_r >= 0
                    and new_c >= 0
                    and new_r < m
                    and new_c < n
                    and not visited[new_r][new_c]
                    ):
                        heappush(min_heap, (grid[new_r][new_c], new_r, new_c))
                        # Mark as visited
                        visited[new_r][new_c] = True

            # Store the result for this query
            ans[idx] = total_pts
        
        return ans
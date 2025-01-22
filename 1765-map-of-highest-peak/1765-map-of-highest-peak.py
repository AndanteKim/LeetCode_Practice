class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        def _is_valid(i: int, j: int) -> bool:
            return 0 <= i < m and 0 <= j < n
        
        dx, dy = (0, 0, 1, -1), (1, -1, 0, 0)
        m, n = len(isWater), len(isWater[0])

        # Initialize the height matrix with -1 (unprocessed cells)
        cell_heights = [[-1] * n for _ in range(m)]

        # Queue to perform breadth-first search
        cell_queue = deque()

        # Add all water cells to the queue and set their height to 0
        for x in range(m):
            for y in range(n):
                if isWater[x][y]:
                    cell_queue.append((x, y))
                    cell_heights[x][y] = 0

        # Initial heights for land cells adjacent to water
        height_of_next_layer = 1
        
        # Perform BFS
        while cell_queue:
            layer_size = len(cell_queue)

            # Iterate through all cells in the current layer
            for _ in range(layer_size):
                curr_cell = cell_queue.popleft()

                # Check all four possible directions for neighboring cells
                for d in range(4):
                    next_x, next_y = curr_cell[0] + dx[d], curr_cell[1] + dy[d]

                    # Check if the neighbor is valid and unprocessed
                    if _is_valid(next_x, next_y) and cell_heights[next_x][next_y] == -1:
                        cell_heights[next_x][next_y] = height_of_next_layer
                        cell_queue.append((next_x, next_y))

            # Increment height for the next layer
            height_of_next_layer += 1

        return cell_heights
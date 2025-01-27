class UnionFind:
    def __init__(self, n: int):
        # Initialize all cells as individial components
        self.parent = [-1] * (n * n)
        self.rank = [1] * (n * n)

    def find(self, index: int) -> int:
        # Find with path compression for better performance
        if self.parent[index] == -1:
            return index
        
        self.parent[index] = self.find(self.parent[index])
        return self.parent[index]

    def union(self, idx1: int, idx2: int) -> None:
        # Union by linking roots directly
        root1, root2 = self.find(idx1), self.find(idx2)

        if root1 == root2:  # Already in same component
            return

        # Make the root with the higher rank the parent of the other root
        if self.rank[root1] < self.rank[root2]:
            self.parent[root1] = root2
        elif self.rank[root1] > self.rank[root2]:
            self.parent[root2] = root1
        else:
            self.parent[root2] = root1
            self.rank[root1] += 1

class Solution:
    def sumRemoteness(self, grid: List[List[int]]) -> int:
        def _is_valid(row: int, col: int) -> bool:
            # Checks if cell (row, col) is within grid bounds and not blocked
            return 0 <= row < n and 0 <= col < n and grid[row][col] != -1
        
        def _get_index(row: int, col: int) -> int:
            # Converts 2D coordinates to 1D index
            return n * row + col
        
        # Direction arrays for moving up, down, left, right
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        n = len(grid)

        # Initialize Union-Find data structure with size n * n
        uf = UnionFind(n)

        # First pass: Connect all adjacent non-blocked cells into components
        for row in range(n):
            for col in range(n):
                # Skip blocked cells
                if grid[row][col] == -1:
                    continue

                # For each valid cell, check all 4 adjacent cells
                for di, dj in dirs:
                    new_r, new_c = row + di, col + dj

                    # If adjacent cell is valid, connect it to current cells
                    if _is_valid(new_r, new_c):
                        # Convert 2D coordinates to 1D index and union them
                        uf.union(_get_index(row, col), _get_index(new_r, new_c))

        # Second pass: Calculate sum of values in each connected component
        comp_sum = dict()   # Maps component root to its sum
        total_sum = 0

        for row in range(n):
            for col in range(n):
                if grid[row][col] == -1:
                    continue

                # Find the root of current cell's component
                parent = uf.find(_get_index(row, col))

                # Add current cell's value to its component sum
                comp_sum[parent] = comp_sum.get(parent, 0) + grid[row][col]
                total_sum += grid[row][col]

        # Third pass: Calculate remoteness sum
        # For each cell, remotenesss = (total_sum - sum of its component)
        ans = sum(total_sum - comp_sum[uf.find(_get_index(row, col))] for row in range(n) for col in range(n) if grid[row][col] != -1)

        return ans

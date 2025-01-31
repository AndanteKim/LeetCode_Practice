class UnionFind:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.island_size = [1] * n

    # Function to find the root of a node with path compression
    def find(self, node: int) -> int:
        if self.parent[node] == node:
            return node
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    # Function to union two sets based on size
    def union(self, node1: int, node2: int) -> None:
        root1, root2 = self.find(node1), self.find(node2)

        # Already in the same set
        if root1 == root2:
            return

        # Union by size: Attach the smaller island to the larger one
        if self.island_size[root1] < self.island_size[root2]:
            # Attach root1 to root2
            self.parent[root1] = root2
            # Update size of root2's island
            self.island_size[root2] += self.island_size[root1]

        else:
            # Attach root2 to root1
            self.parent[root2] = root1
            # Update size of root1's island
            self.island_size[root1] += self.island_size[root2]

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        def is_valid(i: int, j: int) -> bool:
            return 0 <= i < m and 0 <= j < n and grid[i][j] == 1
        
        m, n = len(grid), len(grid[0])

        # Initialize DSU for the entire grid
        uf = UnionFind(m * n)

        # Directions
        dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))

        # Step 1: Union adjacent 1's in the grid
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    # Flatten 2D index to 1D
                    curr_node = n * row + col

                    for dr, dc in dirs:
                        next_r, next_c = row + dr, col + dc

                        # Check bounds and ensure the neighbor is also '1'
                        if is_valid(next_r, next_c):
                            neighbor_node = n * next_r + next_c
                            uf.union(curr_node, neighbor_node)
        
        # Step 2: Calculate the maximum possible island size
        max_island_size = 0

        # Flag to check if there are any zeros in the grid
        has_zero = False

        # To store unique roots for a '0's neighbors
        unique_roots = set()

        for row in range(m):
            for col in range(n):
                if grid[row][col] == 0:
                    has_zero = True

                    # Start with the flipped '0'
                    curr_island_size = 1
                    for dr, dc in dirs:
                        next_r, next_c = row + dr, col + dc

                        # Check bounds and ensure the neighbor is '1'
                        if is_valid(next_r, next_c):
                            neighbor_node = n * next_r + next_c

                            root = uf.find(neighbor_node)
                            unique_roots.add(root)
                    
                    # Sum sup the sizes of unique neighboring islands
                    for root in unique_roots:
                        curr_island_size += uf.island_size[root]

                    # Clear the set for the next '0'
                    unique_roots.clear()

                    # Update the result with the largest island size found
                    max_island_size = max(max_island_size, curr_island_size)

        # If there are no zeros, the largest island is the entire grid
        return m * n if not has_zero else max_island_size
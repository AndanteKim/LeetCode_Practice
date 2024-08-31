# Union-Find class
class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n
        
    # Find the root of element 'u', using the path-compression technique.
    def find(self, u: int) -> int:
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    
    # Union two components of elements 'u' and 'v' respectively based on their ranks.
    def union(self, u: int, v: int) -> None:
        root_u, root_v = self.find(u), self.find(v)
        
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1
                
class Solution:
    # Directions in which we can traverse inside the grids
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    # Helper method to check if the cell at the position (x, y) in the 'grid'
    # is a land cell.
    def is_cell_land(self, x: int, y: int, grid: List[List[int]]) -> bool:
        return grid[x][y] == 1
    
    # Helper method to convert (x, y) position to a 1-dimensional index.
    def convert_to_index(self, x: int, y: int) -> int:
        return x * self.cols + y
    
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        self.rows, self.cols = len(grid2), len(grid2[0])
        uf = UnionFind(self.rows * self.cols)
        
        # Traverse each land cell of 'grid2'.
        for x in range(self.rows):
            for y in range(self.cols):
                if self.is_cell_land(x, y, grid2):
                    # Union adjacent land cells with the current land cell.
                    for dx, dy in self.directions:
                        next_x, next_y = x + dx, y + dy
                        if 0 <= next_x < self.rows and 0 <= next_y < self.cols and self.is_cell_land(next_x, next_y, grid2):
                            uf.union(self.convert_to_index(x, y), self.convert_to_index(next_x, next_y))
                            
        # Traverse 'grid2' land cells and mark that cell's root as not a sub-island
        # if the land cell isn't present at the respective position in 'grid1'.
        is_sub_island = [True] * (self.rows * self.cols)
        
        for x in range(self.rows):
            for y in range(self.cols):
                if self.is_cell_land(x, y, grid2) and not self.is_cell_land(x, y, grid1):
                    root = uf.find(self.convert_to_index(x, y))
                    is_sub_island[root] = False
                    
        # Count all the sub-islands.
        sub_island_counts = 0
        for x in range(self.rows):
            for y in range(self.cols):
                if self.is_cell_land(x, y, grid2):
                    root = uf.find(self.convert_to_index(x, y))
                    if is_sub_island[root]:
                        sub_island_counts += 1
                        
                        # One cell can be the root of multiple land cells, so to
                        # avoid counting the same island multiple times, mark it as false.
                        is_sub_island[root] = False
                        
        return sub_island_counts
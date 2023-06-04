class UnionFind:
    def __init__(self, size: int):
        self.parent = [x for x in range(size)]
        self.rank = [0] * size
    
    def find(self, i: int) -> int:
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
    
    def union(self, x: int, y: int) -> None:
        parent_x, parent_y = self.find(x), self.find(y)
        if parent_x != parent_y:
            if self.rank[parent_x] > self.rank[parent_y]:
                self.parent[parent_y] = parent_x
            elif self.rank[parent_x] < self.rank[parent_y]:
                self.parent[parent_x] = parent_y
            else:
                self.parent[parent_y] = parent_x
                self.rank[parent_x] += 1

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row, col = len(heights), len(heights[0])
        if row == 1 and col == 1:
            return 0
        
        edge_list = []
        for curr_row in range(row):
            for curr_col in range(col):
                if curr_row > 0:
                    diff = abs(heights[curr_row][curr_col] - heights[curr_row - 1][curr_col])
                    edge_list.append((diff, curr_row * col + curr_col, (curr_row - 1) * col + curr_col))
                if curr_col > 0:
                    diff = abs(heights[curr_row][curr_col] - heights[curr_row][curr_col - 1])
                    edge_list.append((diff, curr_row * col + curr_col, curr_row * col + curr_col - 1))
        
        edge_list.sort()
        union_find = UnionFind(row * col)
        
        for diff, x, y in edge_list:
            union_find.union(x, y)
            if union_find.find(0) == union_find.find(row * col - 1):
                return diff
        return -1
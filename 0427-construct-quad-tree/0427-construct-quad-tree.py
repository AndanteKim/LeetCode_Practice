"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def sameValue(self, grid: List[List[int]], x1: int, y1: int, length: int) -> bool:
        for i in range(x1, x1 + length):
            for j in range(y1, y1 + length):
                if grid[i][j] != grid[x1][y1]:
                    return False
        return True
    
    def solve(self, grid: List[List[int]], x1: int, y1: int, length: int) -> 'Node':
        if self.sameValue(grid, x1, y1, length):
            return Node(grid[x1][y1], True)
        else:
            root = Node(False, False)
            
            root.topLeft = self.solve(grid, x1, y1, length // 2)
            root.topRight = self.solve(grid, x1, y1 + length // 2, length // 2)
            root.bottomLeft = self.solve(grid, x1 + length // 2, y1, length // 2)
            root.bottomRight = self.solve(grid, x1 + length // 2, y1 + length // 2, length // 2)
            return root
    
    def construct(self, grid: List[List[int]]) -> 'Node':
        return self.solve(grid, 0, 0, len(grid))
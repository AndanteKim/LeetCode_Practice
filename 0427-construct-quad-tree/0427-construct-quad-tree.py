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
    def solve(self, grid: List[List[int]], x1: int, y1: int, length: int) -> 'Node':
        if length == 1:
            return Node(grid[x1][y1], True)
        
        topLeft = self.solve(grid, x1, y1, length // 2)
        topRight = self.solve(grid, x1, y1 + length // 2, length // 2)
        bottomLeft = self.solve(grid, x1 + length // 2, y1, length // 2)
        bottomRight = self.solve(grid, x1 + length // 2, y1 + length // 2, length // 2)
        
        if topLeft.isLeaf and topRight.isLeaf and bottomLeft.isLeaf and bottomRight.isLeaf\
        and topLeft.val == topRight.val and topRight.val == bottomLeft.val\
        and bottomLeft.val == bottomRight.val:
            return Node(topLeft.val, True)
        
        return Node(False, False, topLeft, topRight, bottomLeft, bottomRight)
    
    def construct(self, grid: List[List[int]]) -> 'Node':
        return self.solve(grid, 0, 0, len(grid))
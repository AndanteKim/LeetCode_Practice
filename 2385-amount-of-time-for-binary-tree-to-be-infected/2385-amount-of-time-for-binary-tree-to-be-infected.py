# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.max_dist = 0
    
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        self.traverse(root, start)
        return self.max_dist
    
    def traverse(self, root: Optional[TreeNode], start: int) -> int:
        depth = 0
        
        # base case: if it is a leaf
        if not root:
            return depth
        
        left_depth = self.traverse(root.left, start)
        right_depth = self.traverse(root.right, start)
        
        # when the current node reaches to start point
        if root.val == start:
            self.max_dist = max(left_depth, right_depth)
            depth = -1
            
        elif left_depth >= 0 and right_depth >= 0:
            depth = max(left_depth, right_depth) + 1
            
        else:
            dist = abs(left_depth) + abs(right_depth)
            self.max_dist = max(self.max_dist, dist)
            depth = min(left_depth, right_depth) - 1
        
        return depth
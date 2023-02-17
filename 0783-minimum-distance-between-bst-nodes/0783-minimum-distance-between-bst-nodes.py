# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        min_dist, queue = float('inf'), deque([root])
        visited_nodes = []
        while queue:
            parent = queue.popleft()
            
            if parent.left:
                queue.append(parent.left)
                min_dist = min(min_dist, abs(parent.val - parent.left.val))
                
            if parent.right:
                queue.append(parent.right)
                
                min_dist = min(min_dist, abs(parent.val - parent.right.val))
            for node in visited_nodes:
                min_dist = min(min_dist, abs(parent.val - node.val))
            visited_nodes.append(parent)
                
        return 0 if min_dist == float('inf') else min_dist
        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        if not root: return 0
        
        def is_leaf(node):
            return node is not None and node.left is None and node.right is None
        
        stack, total = [root], 0
        
        while stack:
            sub_root = stack.pop()
            
            if is_leaf(sub_root.left):
                total += sub_root.left.val
                
            if sub_root.right:
                stack.append(sub_root.right)
            
            if sub_root.left:
                stack.append(sub_root.left)
                
        return total
        
            
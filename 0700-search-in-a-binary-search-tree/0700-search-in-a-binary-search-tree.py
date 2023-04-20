# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        
        if not root:
            return None
        
        stack = [root]
        while stack:
            node = stack.pop()
            
            if node.val == val:
                return node
            
            if node.right:
                stack.append(node.right)
            
            if node.left:
                stack.append(node.left)
            
        return None
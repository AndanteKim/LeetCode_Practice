# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        
        stack = [root]
        
        while stack:
            node = stack.pop()
            if not node.left and val < node.val:
                node.left = TreeNode(val)
                break
            if not node.right and val > node.val:
                node.right = TreeNode(val)
                break
                
            if node.right and val > node.val:
                stack.append(node.right)
            
            if node.left and val < node.val:
                stack.append(node.left)
            
        return root
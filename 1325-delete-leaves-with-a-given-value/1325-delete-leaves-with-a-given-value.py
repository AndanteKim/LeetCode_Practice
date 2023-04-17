# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if not root:
            return None
        
        stack = [(root, None, False)]
        
        while stack:
            child, parent, visited = stack.pop()
            
            if visited:
                if not child.left and not child.right and child.val == target:
                    if not parent:
                        return None
                    elif parent.left == child:
                        parent.left = None
                    elif parent.right == child:
                        parent.right = None
            else:
                stack.append((child, parent, True))
                if child.right:
                    stack.append((child.right, child, False))
            
                if child.left:
                    stack.append((child.left, child, False))
               
        return root
        
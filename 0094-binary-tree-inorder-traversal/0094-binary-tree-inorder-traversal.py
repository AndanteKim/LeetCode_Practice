# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        stack, ans = [(root, False)], []
        while stack:
            node, visited = stack.pop()
            
            if not visited:
                if node.right:
                    stack.append((node.right, False))
                stack.append((node, True))
                
                if node.left:
                    stack.append((node.left, False))
            else:
                ans.append(node.val)
            
        return ans
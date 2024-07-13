# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        ans = 0
        
        while root:
            if root.left:
                predecessor = root.left
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right
                    
                if not predecessor.right:
                    predecessor.right = root
                    root = root.left
                    ans += 1
                else:
                    predecessor.right = None
                    root = root.right
                
            else:
                ans += 1
                root = root.right
        
        return ans
        
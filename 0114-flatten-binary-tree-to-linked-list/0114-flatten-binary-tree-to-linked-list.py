# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # Handle the null scenario
        if not root:
            return
        
        node = root
        while node:
            # If the node has a left child
            if node.left:
                # Find the rightmost node
                rightmost = node.left
                while rightmost.right:
                    rightmost = rightmost.right
                    
                # Rewire the connections
                rightmost.right = node.right
                node.right = node.left
                node.left = None
                
            # move on to the right side of the tree
            node = node.right
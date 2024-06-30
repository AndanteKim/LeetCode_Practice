# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def splitBST(self, root: Optional[TreeNode], target: int) -> List[Optional[TreeNode]]:
        # Base case: if root is None, return two None values
        if not root:
            return [None, None]
        
        # If root's value is greater than target,
        # recursively split left subtree
        if root.val > target:
            left = self.splitBST(root.left, target)
            
            # Attach the right part of the split to root's left subtree
            root.left = left[1]
            return [left[0], root]
        
        # Otherwise, recursively split right subtree
        else:
            right = self.splitBST(root.right, target)
            # Attach the left part of the split to root's right subtree
            root.right = right[0]
            return [root, right[1]]
        
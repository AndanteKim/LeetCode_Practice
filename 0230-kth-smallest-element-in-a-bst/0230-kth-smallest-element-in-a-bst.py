# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node: TreeNode) -> None:
            if not node:
                return

            inorder(node.left)
            if self.k == k:
                self.ans = node.val
            self.k += 1
            inorder(node.right)
            
        self.ans, self.k = -1, 1
        inorder(root)
        
        return self.ans
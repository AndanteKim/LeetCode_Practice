# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode]) -> List[int]:
        if not node:
            return []
        return self.dfs(node.left) + [node.val] + self.dfs(node.right)
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        inorder_traversal = self.dfs(root)
        
        for i in range(1, len(inorder_traversal)):
            if inorder_traversal[i] - inorder_traversal[i - 1] <= 0:
                return False
        
        return True
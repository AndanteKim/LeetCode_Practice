# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def dfs(curr: TreeNode) -> List[TreeNode]:
            if not curr:
                return []
            
            return dfs(curr.left) + [curr] + dfs(curr.right)
        
        inorder = dfs(root)
        for i in range(len(inorder) - 2, -1, -1):
            inorder[i].val += inorder[i + 1].val
        
        return root
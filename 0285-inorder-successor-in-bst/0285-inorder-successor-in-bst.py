# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        def dfs(curr: TreeNode) -> None:
            if not curr:
                return

            if curr.val > p.val and (self.ans == None or self.ans.val > curr.val):
                self.ans = curr

            dfs(curr.left)
            dfs(curr.right)
        
        self.ans = None
        dfs(root)
        if self.ans:
            self.ans.left, self.ans.right = None, None
        return self.ans
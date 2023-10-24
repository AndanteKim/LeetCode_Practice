# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node: Optional[TreeNode], level: int) -> None:
            if not node:
                return
            
            if len(ans) == level:
                ans.append(node.val)
            else:
                ans[level] = max(ans[level], node.val)
            
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)
        
        ans = []
        dfs(root, 0)
        return ans
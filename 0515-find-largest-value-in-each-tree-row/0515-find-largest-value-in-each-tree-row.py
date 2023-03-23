# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], level: int, ans: List[int]) -> None:
        if not node:
            return
        
        if level == len(ans):
            ans.append(node.val)
        ans[level] = max(ans[level], node.val)
        
        self.dfs(node.left, level + 1, ans)
        self.dfs(node.right, level + 1, ans)
    
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        
        self.dfs(root, 0, ans);
        
        return ans;
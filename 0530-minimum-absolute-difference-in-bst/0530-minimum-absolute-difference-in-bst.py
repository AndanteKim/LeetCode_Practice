# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], flatten = []) -> List[int]:
        if not node:
            return []
        
        return self.dfs(node.left) + [node.val] + self.dfs(node.right)
        
    
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        elems = self.dfs(root, [])
        ans, prev = float('inf'), elems.pop()
        while elems:
            curr = elems.pop()
            ans = min(ans, abs(curr - prev))
            prev = curr
        
        return ans
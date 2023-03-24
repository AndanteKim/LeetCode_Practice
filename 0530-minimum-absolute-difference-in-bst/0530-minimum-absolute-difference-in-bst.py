# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def iterative_dfs(self, node: Optional[TreeNode]) -> List[int]:
        stack, values = [], []
        curr = node
        
        while stack or curr:
            if curr:
                stack.append(curr)
                curr = curr.left
            else:
                curr = stack.pop()
                values.append(curr.val)
                curr = curr.right
        return values
    
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        values = self.iterative_dfs(root)
        ans = float('inf')
        for i in range(1, len(values)):
            ans = min(ans, values[i] - values[i - 1])
            
        return ans
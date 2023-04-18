# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root:
            return 0
        
        ans, h = 0, defaultdict(int)
        stack = [(root, 0, False)]
        
        while stack:
            node, curr_sum, visited = stack.pop()
            if visited:
                h[curr_sum] -= 1
                continue
            
            curr_sum += node.val
            
            if curr_sum == targetSum:
                ans += 1
            
            ans += h[curr_sum - targetSum]
            
            h[curr_sum] += 1
            stack.append((node, curr_sum, True))
            
            if node.right:
                stack.append((node.right, curr_sum, False))
            
            if node.left:
                stack.append((node.left, curr_sum, False))
            
        return ans
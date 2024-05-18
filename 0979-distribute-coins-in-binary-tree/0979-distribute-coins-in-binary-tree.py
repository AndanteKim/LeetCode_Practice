# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        stack, visited = [root], []
        
        while stack:
            node = stack.pop()
            
            visited.append(node)
            
            if node.left:
                stack.append(node.left)
                
            if node.right:
                stack.append(node.right)
        
        
        ans = 0
        while visited:
            curr = visited.pop()
            
            if curr.left:
                ans += abs(curr.left.val - 1)
                curr.val += curr.left.val - 1
            
            if curr.right:
                ans += abs(curr.right.val - 1)
                curr.val += curr.right.val - 1
                
        return ans
    
        
        
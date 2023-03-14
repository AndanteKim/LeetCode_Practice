# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        total = 0
        def dfs(root, arr):
            nonlocal total
            
            if not root.left and not root.right:
                arr += [root.val]
                num = 0
                digit = len(arr) - 1
                for i in range(len(arr)):
                    num += arr[i] * (10 ** digit)
                    digit -= 1
                
                total += num
                return
            
            if root.left:
                dfs(root.left, arr + [root.val])
            if root.right:
                dfs(root.right, arr + [root.val])
                
        dfs(root, [])
        
        return total
        
        
        
        
        
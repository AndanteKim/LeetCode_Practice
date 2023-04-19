# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        ans, stack = 0, [(root, 0, None)]
        
        while stack:
            node, zigzag, direction = stack.pop()
            
            ans = max(ans, zigzag)
            
            if node.left:
                if direction == 'l':
                    stack.append((node.left, 1, 'l'))
                else:
                    stack.append((node.left, zigzag + 1, 'l'))
                
            if node.right:
                if direction == 'r':
                    stack.append((node.right, 1, 'r'))
                else:
                    stack.append((node.right, zigzag + 1, 'r'))
        
        return ans
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        root_to_leaf = curr_number = 0
        
        while root:
            if root.left:
                predecessor = root.left
                steps = 1
                while predecessor.right and not predecessor.right == root:
                    predecessor = predecessor.right
                    steps += 1
                
                if not predecessor.right:
                    curr_number = curr_number * 10 + root.val
                    predecessor.right = root
                    root = root.left
                
                else:
                    if not predecessor.left:
                        root_to_leaf += curr_number
                    
                    for _ in range(steps):
                        curr_number //= 10
                    predecessor.right = None
                    root = root.right
            else:
                curr_number = curr_number * 10 + root.val
                if not root.right:
                    root_to_leaf += curr_number
                root = root.right
                
        return root_to_leaf
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        total_sum = 0
        current_node = root
        while current_node:
            if not current_node.left:
                current_node = current_node.right
                
            else:
                previous = current_node.left
                
                if not (previous.left or previous.right):
                    total_sum += previous.val
                
                while previous.right and previous.right != current_node:
                    previous = previous.right
                
                if not previous.right:
                    previous.right = current_node
                    current_node = current_node.left
                else:
                    previous.right = None
                    current_node = current_node.right
        return total_sum
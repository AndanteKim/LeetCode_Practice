# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        def post_order(node: Optional[TreeNode]) -> Tuple[int]:
            nonlocal count
            if not node:
                return (0, 0)
            
            left = post_order(node.left)
            right = post_order(node.right)
            
            node_sum = left[0] + right[0] + node.val
            node_count = left[1] + right[1] + 1
            
            # check if the average of the subtree == node value
            if node.val == node_sum // node_count:
                count += 1
            return (node_sum, node_count)
        
        count = 0
        post_order(root)
        return count
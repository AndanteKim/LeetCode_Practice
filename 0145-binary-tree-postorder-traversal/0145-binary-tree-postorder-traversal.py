# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def post_order(curr: Optional[TreeNode]) -> List[int]:
            if not curr:
                return []
            
            return post_order(curr.left) + post_order(curr.right) + [curr.val]
            
        return post_order(root)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def post_order(curr: TreeNode) -> None:
            if not curr:
                return
            
            post_order(curr.left)
            post_order(curr.right)
            ans.append(curr.val)
            
        ans = []
        post_order(root)
        return ans
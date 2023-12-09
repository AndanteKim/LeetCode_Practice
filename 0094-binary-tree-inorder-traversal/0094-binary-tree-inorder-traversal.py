# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans, curr = [], root
        
        while curr:
            # If there is not left side of subtree
            if not curr.left:
                ans.append(curr.val)
                curr = curr.right
            else:
                pre = curr.left
                while pre.right:
                    pre = pre.right
                # connect curr from the rightmost side of subtree to return to the origin curr
                pre.right = curr
                temp = curr
                curr = curr.left
                temp.left = None
        
        return ans
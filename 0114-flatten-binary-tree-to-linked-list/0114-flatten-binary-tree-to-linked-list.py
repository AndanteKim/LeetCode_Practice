# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def preorder(curr: Optional[TreeNode]) -> None:
            if not curr:
                return
            flatten.append(curr.val)
            preorder(curr.left)
            preorder(curr.right)
        
        if not root:
            return root
        
        curr, flatten = root, []
        preorder(curr)
        
        curr = root
        curr.left, curr.right = None, None
        for elem in flatten[1:]:
            curr.right = TreeNode(elem)
            curr = curr.right
            
        return root
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, in_left: int, in_right: int) -> Optional[TreeNode]:
        if in_left > in_right:
            return None
        
        val = self.postorder.pop()
        root = TreeNode(val)
        
        index = self.idx_map[val]
        
        root.right = self.helper(index + 1, in_right)
        root.left = self.helper(in_left, index - 1)
        return root
    
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.idx_map = {val: idx for idx, val in enumerate(inorder)}
        self.postorder = postorder
        self.inorder = inorder
        
        return self.helper(0, len(inorder) - 1)
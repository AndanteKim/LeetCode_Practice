# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, node: Optional[TreeNode]) -> List[int]:
        return self.inorder(node.left) + [node.val] + self.inorder(node.right) if node else []
    
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        return min(self.inorder(root), key = lambda x: abs(target - x))
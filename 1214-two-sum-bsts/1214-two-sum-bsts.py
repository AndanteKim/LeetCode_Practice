# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, seen: Set[int], root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.inorder(seen, root.left)
        seen.add(root.val)
        self.inorder(seen, root.right)
    
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        seen1, seen2 = set(), set()
        self.inorder(seen1, root1)
        self.inorder(seen2, root2)
        for n1 in seen1:
            if target - n1 in seen2:
                return True
        
        return False
            
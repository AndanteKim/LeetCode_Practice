# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def inorder(node: Optional[TreeNode], seen: Set[int]) -> None:
            if not node:
                return
            
            inorder(node.left, seen)
            seen.add(node.val)
            inorder(node.right, seen)
        
        seen1, seen2 = set(), set()
        inorder(root1, seen1)
        inorder(root2, seen2)

        for node1 in seen1:
            if target - node1 in seen2:
                return True

        return False
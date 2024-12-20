# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def traverse_dfs(left_child: TreeNode, right_child: TreeNode, level: int) -> None:
            if not (left_child and right_child):
                return
            
            # If the current level is even, swap the values of the children.
            if level % 2 == 0:
                left_child.val, right_child.val = right_child.val, left_child.val
            
            traverse_dfs(left_child.left, right_child.right, level + 1)
            traverse_dfs(left_child.right, right_child.left, level + 1)
        
        # Base case
        if not root:
            return root
        traverse_dfs(root.left, root.right, 0)
        
        return root
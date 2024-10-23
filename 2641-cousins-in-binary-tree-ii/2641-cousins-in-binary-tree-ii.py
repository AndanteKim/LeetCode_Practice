# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _calculate_level_sum(self, node: Optional[TreeNode], level: int) -> None:
        if not node:
            return
        
        if len(self.level_sums) == level:
            self.level_sums.append(node.val)
        else:
            self.level_sums[level] += node.val
        
        self._calculate_level_sum(node.left, level + 1)
        self._calculate_level_sum(node.right, level + 1)
        
    def _replace_internal(self, node: Optional[TreeNode], sibling_sum: int, level: int) -> None:
        if not node:
            return
        
        left_child_val = node.left.val if node.left else 0
        right_child_val = node.right.val if node.right else 0
        
        if level == 0 or level == 1:
            node.val = 0
        else:
            node.val = self.level_sums[level] - node.val - sibling_sum
        self._replace_internal(node.left, right_child_val, level + 1)
        self._replace_internal(node.right, left_child_val, level + 1)
    
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.level_sums = []
        self._calculate_level_sum(root, 0)
        self._replace_internal(root, 0, 0)
        
        return root
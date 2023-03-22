# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, node: Optional[TreeNode], level: int) -> None:
        if level == len(self.rightside):
            self.rightside.append(node.val)
        for child in [node.right, node.left]:
            if child:
                self.helper(child, level + 1)
    
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        self.rightside = []
        
        self.helper(root, 0)
        return self.rightside
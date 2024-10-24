# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find_canonical_form(self, node: TreeNode) -> None:
        if not node:
            return
        
        # Post-order traversal: first bring subtrees into their canonical form
        self.find_canonical_form(node.left)
        self.find_canonical_form(node.right)
        
        if not node.right:
            return
        
        # Swap subtrees, so that left is non-empty
        if not node.left:
            node.left = node.right
            node.right = None
            return
        
        left = node.left
        right = node.right
        
        # Swap subtrees
        if left.val > right.val:
            node.left, node.right = node.right, node.left
    
    def are_equivalent(self, node1: TreeNode, node2: TreeNode) -> bool:
        if not (node1 or node2):
            return True
        
        if not (node1 and node2):
            return False
        
        if node1.val != node2.val:
            return False
        
        return self.are_equivalent(node1.left, node2.left) and self.are_equivalent(node1.right, node2.right)
    
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        self.find_canonical_form(root1)
        self.find_canonical_form(root2)
        
        return self.are_equivalent(root1, root2)
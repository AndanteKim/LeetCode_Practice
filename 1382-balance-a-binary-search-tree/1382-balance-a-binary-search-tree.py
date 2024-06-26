# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def inorder_traversal(curr: TreeNode) -> List[int]:
            if not curr:
                return []

            return inorder_traversal(curr.left) + [curr.val] + inorder_traversal(curr.right)
        
        
        inorder = inorder_traversal(root)
        n = len(inorder)
        
        # Construct and return the balanced BST
        return self.create_balanced_bst(inorder, 0, n - 1)
    
    def create_balanced_bst(self, inorder: List[int], start: int, end: int) -> TreeNode:
        # Base case: If the start index is greater than the end index, return None.
        if start > end:
            return None
        
        # Find the middle element of the current range
        mid = start + ((end - start) >> 1)
        
        # Recursively construct the left and right subtrees
        left_subtree = self.create_balanced_bst(inorder, start, mid - 1)
        right_subtree = self.create_balanced_bst(inorder, mid + 1, end)
        
        # Create a new node with the middle element and attach the subtrees
        node = TreeNode(inorder[mid], left_subtree, right_subtree)
        
        return node
            
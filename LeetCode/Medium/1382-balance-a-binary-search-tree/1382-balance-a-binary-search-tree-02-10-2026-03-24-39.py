# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def inorder_traversal(node: Optional[TreeNode]) -> None:
            if not node:
                return
            
            inorder_traversal(node.left)
            inorder.append(node.val)
            inorder_traversal(node.right)

        def create(start: int, end: int) -> Optional[TreeNode]:
            if start > end:
                return None

            mid = start + ((end - start) >> 1)

            # Recursively construct the left and right subtrees
            left_subtree = create(start, mid - 1)
            right_subtree = create(mid + 1, end)

            node = TreeNode(inorder[mid], left_subtree, right_subtree)
            return node
        
        inorder = []
        inorder_traversal(root)
        
        return create(0, len(inorder) - 1)
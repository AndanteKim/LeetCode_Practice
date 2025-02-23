# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # Helper function to construct the tree recursively
        def construct_tree(pre_start: int, pre_end: int, post_start: int) -> Optional[TreeNode]:
            # Base case: If there are no nodes to process, return None
            if pre_start > pre_end:
                return None

            # Base case: If only one node is left, return that node
            if pre_start == pre_end:
                return TreeNode(preorder[pre_start])
            
            # The left child root in preoreder traversal (next element after root)
            left_root = preorder[pre_start + 1]

            # Calculate the number of nodes in the left subtree by searching in postorder
            num_of_nodes_in_left = 1
            while left_root != postorder[post_start + num_of_nodes_in_left - 1] != left_root:
                num_of_nodes_in_left += 1

            root = TreeNode(preorder[pre_start])

            # Recursively construct the left subtree
            root.left = construct_tree(pre_start + 1, pre_start + num_of_nodes_in_left, post_start)
            
            # Recursively construct the right subtree
            root.right = construct_tree(pre_start + num_of_nodes_in_left + 1, pre_end, post_start + num_of_nodes_in_left)

            return root
        

        num_of_nodes = len(preorder)
        return construct_tree(0, num_of_nodes - 1, 0)
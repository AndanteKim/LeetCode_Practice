# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        def _traverse_left_to_right(node: TreeNode, curr_height: int) -> None:
            if not node:
                return
            
            # Store the maximum height if this node were removed
            max_height_after_removal[node.val] = self.curr_max_height
            
            # Update the current maximum height
            self.curr_max_height = max(self.curr_max_height, curr_height)
            
            # Traverse left subtree first, then right
            _traverse_left_to_right(node.left, curr_height + 1)
            _traverse_left_to_right(node.right, curr_height + 1)
            
        def _traverse_right_to_left(node: TreeNode, curr_height: int) -> None:
            if not node:
                return
            
            # Update the maximum height if this node were removed
            max_height_after_removal[node.val] = max(max_height_after_removal[node.val], self.curr_max_height)
            
            # Update the current maximum height
            self.curr_max_height = max(curr_height, self.curr_max_height)
            
            # Traverse right subtree first, then left.
            _traverse_right_to_left(node.right, curr_height + 1)
            _traverse_right_to_left(node.left, curr_height + 1)
        
        max_height_after_removal = [0] * 100001
        self.curr_max_height = 0
        _traverse_left_to_right(root, 0)
        self.curr_max_height = 0    # Reset for the second traversal
        _traverse_right_to_left(root, 0)
        
        # Process queries and build the result list
        return [max_height_after_removal[q] for q in queries]
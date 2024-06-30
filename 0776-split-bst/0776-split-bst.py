# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def splitBST(self, root: Optional[TreeNode], target: int) -> List[Optional[TreeNode]]:
        # Create dummy nodes to hold the split tree parts
        dummy_sm, dummy_lg = TreeNode(0), TreeNode(0)
        curr_sm, curr_lg = dummy_sm, dummy_lg
        
        # Start traversal from the root
        curr, next_node = root, None
        
        while curr:
            if curr.val <= target:
                # Attach the current node to the tree
                # with values less than or equal to the target
                curr_sm.right = curr
                curr_sm = curr
                
                # Move to the right subtree
                next_node = curr.right
                
                # Clear the right pointer of current node
                curr_sm.right = None
                curr = next_node
            else:
                # Attach the current node to the treee
                # with values greater to the target
                curr_lg.left = curr
                curr_lg = curr
                
                # Move to the left subtree
                next_node = curr.left
                
                # Clear the left pointer of current node
                curr_lg.left = None
                curr = next_node
                
        # Return the split parts as a list
        return [dummy_sm.right, dummy_lg.left]
        
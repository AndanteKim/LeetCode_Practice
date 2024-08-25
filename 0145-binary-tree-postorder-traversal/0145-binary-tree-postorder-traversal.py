# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # List to store the result of postorder traversal
        ans = []
        
        # Stack to facilitate the traversal of nodes
        traversal_stack = []
        curr_node = root
        
        # Traverse the tree while there are nodes to process
        while curr_node or traversal_stack:
            if curr_node:
                # Add current node's value to result list before going to its children
                ans.append(curr_node.val)
                
                # Push current node onto the stack
                traversal_stack.append(curr_node)
                
                # Move to the right child
                curr_node = curr_node.right
                
            else:
                # Pop the node from the stack and move to its left child
                curr_node = traversal_stack.pop()
                curr_node = curr_node.left
                
        # Reverse the answer list to get the correct postorder sequence
        ans.reverse()
        return ans
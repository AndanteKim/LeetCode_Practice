# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        
        # If the root is null, return an empty list
        if not root:
            return ans
        
        # To keep track of the previously processed node
        prev_node = None
        
        # Stack to manage the traversal
        traversal_stack = []
        
        # Process nodes until both the root is null and the stack is empty
        while root or len(traversal_stack) > 0:
            # Traverse to the leftmost node
            if root:
                traversal_stack.append(root)
                root = root.left
                
            else:
                # Peek at the top node of the stack
                root = traversal_stack[-1]
                
                # If there is no right child or the right child was already processed
                if not root.right or root.right == prev_node:
                    ans.append(root.val)
                    traversal_stack.pop()
                    prev_node = root
                    
                    # Ensure we don't traverse again from this node
                    root = None
                    
                else:
                    # Move to the right child
                    root = root.right
                    
        return ans
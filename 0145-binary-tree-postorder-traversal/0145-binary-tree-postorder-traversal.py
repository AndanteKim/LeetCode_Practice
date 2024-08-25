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
        
        # Stack to manage the traversal
        main_stack = []
        
        # Stack to manage the path
        path_stack = []
        
        # Start with the root node
        main_stack.append(root)
        
        # Process nodes until the main stack is empty
        while main_stack:
            root = main_stack[-1]
            
            # If the node is in the path stack and it's the top, add its value.
            if path_stack and path_stack[-1] == root:
                ans.append(root.val)
                main_stack.pop()
                path_stack.pop()
                
            else:
                # Push the current node to the path stack
                path_stack.append(root)
                
                # Push right child if it exists
                if root.right:
                    main_stack.append(root.right)
                
                # Push left child if it exists
                if root.left:
                    main_stack.append(root.left)
                    
        return ans
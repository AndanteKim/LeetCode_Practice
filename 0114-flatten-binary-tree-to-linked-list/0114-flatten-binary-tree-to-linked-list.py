# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # Handle the null scenario
        if not root:
            return None
        
        START, END = 1, 2
        
        tail_node, stack = None, [(root, START)]
        
        while stack:
            curr_node, recursion_state = stack.pop()
            
            # We reached a lead node. Record this as a tail
            # node and move on.
            if not (curr_node.left or curr_node.right):
                tail_node = curr_node
                continue
            
            # If the node is in the START state, it means we still
            # haven't processed it's left child yet.
            if recursion_state == START:
                
                # If the current node has a left child, we add it
                # to the stack AFTER adding the current node again
                # to the stack with the END recursion state.
                if curr_node.left:
                    stack.append((curr_node, END))
                    stack.append((curr_node.left, START))
                elif curr_node.right:
                    # In case, the current node didn't have a left child
                    # we will add it's right child
                    stack.append((curr_node.right, START))
            else:
                # If the current node is in the END recursion state,
                # that means we did process one of it's children. Left
                # if it existsed, else right
                right_node = curr_node.right
                
                # If there was a left child, there must have been a leaf
                # node and so, we would have set the tail_node
                if tail_node:
                    # Establish the proper connections.
                    tail_node.right = curr_node.right
                    curr_node.right = curr_node.left
                    curr_node.left = None
                    right_node = tail_node.right
                    
                if right_node:
                    stack.append((right_node, START))
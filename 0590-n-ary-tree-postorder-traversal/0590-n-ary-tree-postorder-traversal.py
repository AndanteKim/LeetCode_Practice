"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        # Base case: If the root is None, return the empthy list
        if not root:
            return []
        
        # Stack for traversal and stack to reverse the order
        node_stack, reverse_stack = [root], []
        
        # Traverse the tree using the node_stack
        while node_stack:
            curr = node_stack.pop()
            reverse_stack.append(curr)
            
            # Push all the children of the current node to node_stack
            for child in curr.children:
                node_stack.append(child)
                
        ans = []
        # Pop nodes from reverse_stack and add their values to the answer list
        while reverse_stack:
            curr = reverse_stack.pop()
            ans.append(curr.val)
                
        return ans
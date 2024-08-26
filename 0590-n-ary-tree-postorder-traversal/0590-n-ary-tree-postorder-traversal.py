"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        ans = []
        
        # If the root is None, return the empty list
        if not root:
            return ans
        
        node_stack = [(root, False)]
        
        while node_stack:
            curr_node, is_visited = node_stack.pop()
            
            if is_visited:
                # If the node has been visited, add its value to the result
                ans.append(curr_node.val)
            else:
                # Mark the current node as visited and push it back to the stack
                node_stack.append((curr_node, True))
                
                # Push all children to the stack in reverse order
                for i in range(len(curr_node.children) - 1, -1, -1):
                    node_stack.append((curr_node.children[i], False))
                    
        return ans
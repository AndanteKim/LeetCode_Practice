"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def process_child(self, child_node: 'Node', prev: 'Node', leftmost: 'Node') -> Tuple['Node']:
        if child_node:
            # If the "prev" pointer is already set i.e. if we
            # already found at least one node on the next level,
            # setup its next pointer
            if prev:
                prev.next = child_node
            else:
                # Else it means this child node is the first node
                # we have encountered on the next level, so we
                # set the leftmost pointer
                leftmost = child_node
            prev = child_node
        return prev, leftmost
    
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        
        # The root node is the only node on the first level
        # and hence its the leftmost node for that level
        leftmost = root
        
        # We have no idea about the structure of the tree,
        # so, we keep going until we find the last level.
        # The nodes on the last level won't have any children
        while leftmost:
            # "prev" tracks the lastest node on the "next" level
            # while "curr" tracks the lastest node on the current
            # level.
            prev, curr = None, leftmost
            
            # We reset this, so that we can re-assign it to the leftmost
            # node of the next level. Also, if there isn't one, this
            # would help break us out of the outermost loop.
            leftmost = None
            
            # Iterate on the nodes in the current level using
            # the next pointers already established.
            while curr:
                # Process both the children and update the prev
                # and leftmost pointers as necessary.
                prev, leftmost = self.process_child(curr.left, prev, leftmost)
                prev, leftmost = self.process_child(curr.right, prev, leftmost)
                
                # Move onto the next node.
                curr = curr.next
                
        return root
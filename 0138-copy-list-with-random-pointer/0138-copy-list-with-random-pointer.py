"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def __init__(self):
        # Dictionary holding old nodes as keys and new nodes as its values
        self.visitedHash = dict()
        
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # base case
        if not head:
            return None
        
        if head in self.visitedHash:
            return self.visitedHash[head]
        
        # create a new node with the value same as old node
        node = Node(head.val, None, None)
        
        # Save it in the hash map to find loops during traversal due to randomness of
        # random pointers and to avoid it
        self.visitedHash[head] = node

        # Recursively copy the remaining linked list starting once from the next pointer
        # and then from the random pointer
        # Update two independent recursive calls
        node.next = self.copyRandomList(head.next)
        node.random = self.copyRandomList(head.random)
        
        return node
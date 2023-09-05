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
        # creating a visited dictionary to hold old node reference as key
        # and new node reference as the "value"
        self.visited = dict()
    
    def getClonedNode(self, node: 'Node') -> 'Node':
        # if node exists then
        if node:
            # check if it's in the visited dictionary
            if node in self.visited:
                # If it's in the visited dictionary then return the new node reference
                # from the dictionary
                return self.visited[node]
            else:
                # Otherwise create a new node, save the reference in the visited dictionary
                # and return it
                self.visited[node] = Node(node.val, None, None)
                return self.visited[node]
        
        return None
    
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        
        old_node = head
        # create the new head node
        new_node = Node(old_node.val, None, None)
        self.visited[old_node] = new_node
        
        # Iterate on the linked list until all nodes are cloned
        while old_node:
            # get the clones of the nodes referenced by random and next pointers
            new_node.random = self.getClonedNode(old_node.random)
            new_node.next = self.getClonedNode(old_node.next)
            
            # Move one step ahead in the linked list
            old_node = old_node.next
            new_node = new_node.next
            
        return self.visited[head]
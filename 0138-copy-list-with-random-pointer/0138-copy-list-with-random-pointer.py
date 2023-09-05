"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        
        # creating a new weaved list of original and copied nodes
        ptr = head
        while ptr:
            
            # cloned node
            new_node = Node(ptr.val, None, None)
            
            # Inserting the cloned node just next to the original node
            # If A -> B -> C is the original linked list,
            # Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
            new_node.next = ptr.next
            ptr.next = new_node
            ptr = new_node.next
        
        ptr = head
        
        # Now link the random pointers of the new nodes created
        # Iterate the newly created list and use the original nodes random pointers
        # to assign references to random pointers for cloned nodes
        while ptr:
            ptr.next.random = ptr.random.next if ptr.random else None
            ptr = ptr.next.next
            
        # Unweave the linked list to get back the original linked list
        # and the cloned list i.e. A->A'->B->B'->C->C' would be broken to A->B->C and
        # A'->B'->C'
        ptr_old_list = head # A->B->C
        ptr_new_list = head.next # A'->B'->C'
        head_new = head.next # A'->B'->C'
        while ptr_old_list:
            ptr_old_list.next = ptr_old_list.next.next
            ptr_new_list.next = ptr_new_list.next.next if ptr_new_list.next else None
            ptr_old_list = ptr_old_list.next
            ptr_new_list = ptr_new_list.next
        
        return head_new
        
        
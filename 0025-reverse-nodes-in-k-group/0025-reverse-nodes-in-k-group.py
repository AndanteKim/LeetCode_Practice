# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseLL(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Reverse k nodes of the given linked list.
        # This function assumes thaat the list contains
        # at least k nodes.
        new_head, ptr = None, head
        while k:
            # Keep track of the next node to process in 
            # the original list
            next_node = ptr.next
            
            # Insert the node pointed to by "ptr"
            # at the beginning of the reversed list
            ptr.next = new_head
            new_head = ptr
            
            # Move on to the next node
            ptr = next_node
            
            # Decrement the count of nodes to be reversed by 1
            k -= 1
            
        # Return the head of the reversed list
        return new_head
    
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        cnt, ptr = 0, head
        
        # First, see if there are at least k nodes left
        # in the linked list.
        while cnt < k and ptr:
            ptr = ptr.next
            cnt += 1
            
        # If we have k nodes, then we reverse them.
        if cnt == k:
            # Reverse the first k nodes of the list and 
            # get the reversedd list's head
            reverse_head = self.reverseLL(head, k)
            
            # Now, recurse on the remaining linked list.
            # Since our recursion returns the head of the overall processed
            # list, we use that and the "original" head of the "k" nodes
            # to re-wire the connections.
            head.next = self.reverseKGroup(ptr, k)
            return reverse_head
        
        return head
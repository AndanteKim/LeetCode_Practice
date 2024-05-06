# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse_list(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head
        next_temp = None
        
        # Set each node's next pointer to the previous node
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
            
        return prev
    
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Reverse the original linked list
        head = self.reverse_list(head)
        
        maximum, prev, curr = 0, None, head
        
        # Traverse the list deleting nodes
        while curr:
            maximum = max(maximum, curr.val)
            
            # Deleete nodes that are smaller than maximum
            if curr.val < maximum:
                # Delete current by skipping
                prev.next = curr.next
                deleted = curr
                curr = curr.next
                deleted.next = None
                
            # curr doesn't need to be deleted
            else:
                prev = curr
                curr = curr.next
                
        # Reverse and return the modified linked list
        return self.reverse_list(head)
        
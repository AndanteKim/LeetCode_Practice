# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        # before and after := two pointers with dummy nodes to circulate from each initialization of head pointer
        before = before_head = ListNode()
        after = after_head = ListNode()
        
        while head:
            
            # set the criterion between less than x and greater or equal to x 
            if head.val < x:
                before.next = head
                before = before.next
            
            else:
                after.next = head
                after = after.next
            
            head = head.next
        
        # Cut the cycle of ListNodes greater than x
        after.next = None
        
        # merge two pointers: before and head
        before.next = after_head.next
        
        return before_head.next
        
        
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        start = front
        
        while start:
            prefix_sum = 0
            end = start.next
            
            while end:
                # Add end's value to the prefix_sum
                prefix_sum += end.val
                
                # Delete zero sum consecutive sequence
                # by setting node before sequence to node after
                if prefix_sum == 0:
                    start.next = end.next
                end = end.next
            start = start.next
            
        return front.next
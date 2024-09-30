# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Base case: recursion
        if not (head and head.next):
            return head
        
        # Nodes to be swapped
        first, second = head, head.next
        
        # swapping
        first.next = self.swapPairs(second.next)
        second.next = first
        
        # Now, the head is second node.
        return second
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not (head and head.next):
            return head
        
        sentinel = prev_node = ListNode(-1)
        prev_node.next = head
        
        while head and head.next:
            # Nodes to be swapped
            first, second = head, head.next
            
            # swapping
            first.next = second.next
            second.next = first
            prev_node.next = second
            
            # Reinitialize the pointer
            prev_node, head = first, first.next
        
        return sentinel.next
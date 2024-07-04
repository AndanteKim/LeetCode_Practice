# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize a sentinel/dummy node with the first non-zero value.
        modify = head.next
        next_sum = modify
        
        while next_sum:
            total = 0
            
            # Find the sum oof aall nodes until you encounter a 0.
            while next_sum.val != 0:
                total += next_sum.val
                next_sum = next_sum.next
            
            # Assign the sum to the current node's value.
            modify.val = total
            # Move next_sum to the first non-zero value of the next block.
            next_sum = next_sum.next
            
            # Move modify also to this node.
            modify.next = next_sum
            modify = modify.next
            
        return head.next
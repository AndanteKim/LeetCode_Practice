# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        curr = front
        prefix_sum = 0
        prefix_sum_to_node = {0: front}
        
        # Calculate the prefix sum for each node and add to the hashmap
        # Duplicate prefix sum values will be replaced
        while curr:
            prefix_sum += curr.val
            prefix_sum_to_node[prefix_sum] = curr
            curr = curr.next
            
        # Reset prefix sum and current
        prefix_sum = 0
        curr = front
        
        # Delete zero sum consecutive sequences
        # by setting node before sequence to node after
        while curr:
            prefix_sum += curr.val
            curr.next = prefix_sum_to_node[prefix_sum].next
            curr = curr.next
            
        return front.next
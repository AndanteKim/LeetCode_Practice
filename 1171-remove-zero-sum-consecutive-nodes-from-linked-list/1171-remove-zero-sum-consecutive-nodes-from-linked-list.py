# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        curr = front
        prefix_sum, prefix_sum_to_node = 0, dict()
        
        while curr:
            # Add current's value to the prefix sum
            prefix_sum += curr.val
            
            # If prefix_sum is already in the hashmap,
            # we have found a zero-sum sequence:
            if prefix_sum in prefix_sum_to_node:
                prev = prefix_sum_to_node[prefix_sum]
                curr = prev.next
            
                # Delete zero sum nodes from hashmap
                # to prevent incorrect deletions from linked list
                p = prefix_sum + curr.val
                while p != prefix_sum:
                    del prefix_sum_to_node[p]
                    curr = curr.next
                    p += curr.val
                    
                # Make connection from the node before
                # the zero sum sequence to the node after
                prev.next = curr.next
            else:
                # Add new prefix_sum to hashmap
                prefix_sum_to_node[prefix_sum] = curr
                
            # Progress to next element in list
            curr = curr.next
            
        return front.next
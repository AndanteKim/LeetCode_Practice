# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # base case: After the last jump, the head becomes None.
        if not head or not head.next:
            return head
        
        # Nodes to be swapped
        first_node = head
        second_node = head.next
        
        # Swapping
        first_node.next = self.swapPairs(second_node.next)
        second_node.next = first_node
        
        # Now the head is the second node
        return second_node
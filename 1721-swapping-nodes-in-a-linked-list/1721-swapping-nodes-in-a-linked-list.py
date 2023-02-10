# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        check, length = head, 0
        while check:
            length += 1
            check = check.next
        
        front_node = head
        for i in range(k-1):
            front_node = front_node.next
        
        end_node = head
        for i in range(length - k):
            end_node = end_node.next
        
        front_node.val, end_node.val = end_node.val, front_node.val
        
        return head
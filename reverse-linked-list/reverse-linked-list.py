# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not (head and head.next):
            return head
        
        prev, curr = None, head
        
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        
        return prev
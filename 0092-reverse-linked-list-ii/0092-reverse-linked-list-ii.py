# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head:
            return None
        
        left_head, right_head = head, head
        stop = False
        
        def recurseAndReverse(right_head, m, n):
            nonlocal left_head, stop
            
            if n == 1:
                return
            right_head = right_head.next
            
            if m > 1:
                left_head = left_head.next
            
            recurseAndReverse(right_head, m - 1, n - 1)
            
            if left_head == right_head or right_head.next == left_head:
                stop = True
                
            if not stop:
                left_head.val, right_head.val = right_head.val, left_head.val
                
                left_head = left_head.next
            
        recurseAndReverse(right_head, left, right)
        return head
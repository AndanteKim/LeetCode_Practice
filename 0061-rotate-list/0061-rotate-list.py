# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rec(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 0:
            return head
        
        curr, prev = head, head
        
        while curr.next:
            prev = curr
            curr = curr.next
            
        curr.next = head
        prev.next = None
        head = curr
        curr = prev
        return self.rec(head, k - 1)
    
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Recursive base case
        if not head:
            return head
        
        temp, size = head, 0
        while temp:
            size += 1
            temp = temp.next
        
        k %= size
        
        return self.rec(head, k)
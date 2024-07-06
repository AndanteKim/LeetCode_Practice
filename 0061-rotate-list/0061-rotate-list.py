# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not (head and head.next):
            return head
        
        n, curr = 0, head
        while curr:
            n += 1
            curr = curr.next
        
        k %= n
        while k > 0:
            curr, prev = head, None
            
            while curr.next:
                prev = curr
                curr = curr.next
            
            prev.next = None
            curr.next = head
            head = curr
            
            k -= 1
            
        return head
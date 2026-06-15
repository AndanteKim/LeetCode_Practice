# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n, curr = 0, head
        
        while curr:
            n += 1
            curr = curr.next
        
        if n <= 1:
            return None

        mid, curr = n >> 1, head
        for _ in range(mid - 1):
            curr = curr.next
        
        curr.next = curr.next.next

        return head
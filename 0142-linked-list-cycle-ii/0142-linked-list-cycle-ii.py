# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersect(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tortoise, hare = head, head
        
        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next
            
            if tortoise == hare:
                return tortoise
        
        return None
    
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        intersect = self.getIntersect(head)
        if not intersect:
            return None
        
        ptr1, ptr2 = head, intersect
        
        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next
            
        return ptr1
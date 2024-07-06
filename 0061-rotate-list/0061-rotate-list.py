# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Base cases
        if not (head and head.next):
            return head
        
        # close the linked list into the ring
        old_tail, n = head, 1
        while old_tail.next:
            old_tail = old_tail.next
            n += 1
        old_tail.next = head
        
        # find the new tail: (n - k % n - 1)th node
        # and new head : (n - k % n)th node
        new_tail = head
        
        for i in range(n - k % n - 1):
            new_tail = new_tail.next
        new_head = new_tail.next
        
        # break the ring
        new_tail.next = None
        
        return new_head
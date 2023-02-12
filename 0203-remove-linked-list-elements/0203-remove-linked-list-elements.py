# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        sentinel = curr = ListNode(-1)
        curr.next = head
        while curr and curr.next:
            while curr.next and val == curr.next.val:
                curr.next = curr.next.next
            
            curr = curr.next
        
        return sentinel.next
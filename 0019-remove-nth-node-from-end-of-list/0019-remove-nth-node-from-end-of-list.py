# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head: return None
        
        length, curr = 0, ListNode()
        curr.next = head
        
        while curr:
            length += 1
            curr = curr.next
        
        curr, i = ListNode(), 0
        
        root = curr
        curr.next = head
        while i < length:
            if i == length - n - 1:
                curr.next = curr.next.next
                break
            curr = curr.next
            i += 1
        
        return root.next
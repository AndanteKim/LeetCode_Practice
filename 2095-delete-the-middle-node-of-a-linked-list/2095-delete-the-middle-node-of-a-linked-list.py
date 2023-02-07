# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: return None
        
        length, curr = 0, head
        
        while curr:
            length += 1
            curr = curr.next
        curr, i, middle = head, 0, length // 2 - 1
        while i < length:
            if i == middle:
                curr.next = curr.next.next
                break
            curr = curr.next
            i += 1
            
        return head
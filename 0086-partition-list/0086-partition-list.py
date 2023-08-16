# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        head.next = self.partition(head.next, x)
        
        if head.val < x:
            return head
        else:
            curr = head
            while curr.next:
                if curr.val > curr.next.val and curr.next.val < x:
                    curr.val, curr.next.val = curr.next.val, curr.val
                    curr = curr.next
                else:
                    break
        
        return head
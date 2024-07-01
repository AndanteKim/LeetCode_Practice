# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not (l1 or l2):
            return None
        elif not l1 and l2:
            return l2
        elif l1 and not l2:
            return l1
        
        total = l1.val + l2.val
        nxt = self.addTwoNumbers(l1.next, l2.next)
        
        if total >= 10:
            total %= 10
            nxt = self.addTwoNumbers(nxt, ListNode(1))
        
        return ListNode(total, nxt)
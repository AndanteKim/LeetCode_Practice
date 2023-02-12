# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rec(self, node: Optional[ListNode], val: int) -> Optional[ListNode]:
        if node:
            if node.val == val:
                return self.rec(node.next, val)
            else:
                node.next = self.rec(node.next, val)
            return node
    
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        # recursive review
        return self.rec(head, val)
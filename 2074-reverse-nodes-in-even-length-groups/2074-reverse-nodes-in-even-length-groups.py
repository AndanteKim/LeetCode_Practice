# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, d = head, 2
        
        while prev.next:
            node, n = prev, 0
            
            for _ in range(d):
                if not node.next:
                    break
                n += 1
                node = node.next
                
            if n & 1:
                prev = node
            else:
                node, rev = prev.next, None
                for _ in range(n):
                    node.next, node, rev = rev, node.next, node
                prev.next.next, prev.next, prev = node, rev, prev.next
            d += 1
        return head
        
        
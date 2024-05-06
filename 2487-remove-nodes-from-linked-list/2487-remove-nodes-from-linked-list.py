# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node, dq = head, deque()
        
        while node:
            while dq and node.val > dq[-1].val:
                dq.pop()
            dq.append(node)
            node = node.next
        
        sentinel = ListNode()
        sentinel.next = dq[0]
        
        while len(dq) > 1:
            dq[0].next = dq[1]
            dq.popleft()
            
        return sentinel.next
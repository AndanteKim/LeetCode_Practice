# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        sentinel = ListNode()
        sentinel.next = head
        prev, root, curr = sentinel, head, 0
        
        while root:
            if root.val == 0 and curr > 0:
                root.val = curr
                curr = 0
                prev.next = root
                prev = root
            else:
                curr += root.val
            root = root.next
            
        return sentinel.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        curr, seen = head, dict()
        
        while curr:
            seen[curr.val] = seen.get(curr.val, 0) + 1
            curr = curr.next
        
        sentinel = ListNode()
        sentinel.next = head
        pred, curr = sentinel, head
        
        while curr:
            if seen[curr.val] >= 2:
                pred.next = curr.next
            else:
                pred = pred.next
            
            curr = curr.next
            
        return sentinel.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        
        length, curr = 0, head 
        while curr:
            length += 1
            curr = curr.next
        
        rev, curr, i = None, head, 0
        while i < length // 2:
            curr = curr.next
            i += 1
            
        while i < length:
            next_node = curr.next
            curr.next = rev
            rev = curr
            curr = next_node
            i += 1
        
        ans, slow, i = 0, head, 0
        while i < length // 2:
            curr_val = slow.val + rev.val
            ans = max(ans, curr_val)
            slow = slow.next
            rev = rev.next
            i += 1
        
        return ans
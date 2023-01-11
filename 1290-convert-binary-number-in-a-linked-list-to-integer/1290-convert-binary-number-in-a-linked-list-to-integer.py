# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        origin, length, ans = head, 0, 0
        
        while origin != None:
            length += 1
            origin = origin.next
            
        while head != None:
            ans += head.val * 2 ** (length - 1)
            length -= 1
            head = head.next
        
        return ans
        
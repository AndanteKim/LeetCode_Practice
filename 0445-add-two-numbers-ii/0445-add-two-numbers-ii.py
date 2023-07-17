# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        s1, s2 = [], []
        
        while l1:
            s1.append(l1.val)
            l1 = l1.next
        
        while l2:
            s2.append(l2.val)
            l2 = l2.next
        
        carry, digit = 0, 0
        ans = ListNode()
        while s1 or s2:
            if s1:
                digit += s1.pop()
            if s2:
                digit += s2.pop()
            ans.val = digit % 10
            carry = digit // 10
            head = ListNode(carry)
            head.next = ans
            ans = head
            digit = carry
        return ans.next if carry == 0 else ans
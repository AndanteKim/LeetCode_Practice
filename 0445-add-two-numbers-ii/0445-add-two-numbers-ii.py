# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, temp = None, None
        while head:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        return prev
    
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        r1, r2 = self.reverseList(l1), self.reverseList(l2)
        
        digit, carry = 0, 0
        ans = ListNode()
        while r1 or r2:
            if r1:
                digit += r1.val
                r1 = r1.next
            if r2:
                digit += r2.val
                r2 = r2.next
            ans.val = digit % 10
            carry = digit // 10
            head = ListNode(carry)
            head.next = ans
            ans = head
            digit = carry
        return ans.next if carry == 0 else ans
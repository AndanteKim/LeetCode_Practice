# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        curr1, curr2 = l1, l2
        digit, carry = 0, 0
        ans = curr = ListNode()
        
        while curr1 or curr2:
            if curr1 and curr2:
                carry, digit = divmod(curr1.val + curr2.val + carry, 10)
            elif curr1:
                carry, digit = divmod(curr1.val + carry, 10)
            else:
                carry, digit = divmod(curr2.val + carry, 10)
            
            curr.val = digit
                
            if curr1:
                curr1 = curr1.next
                
            if curr2:
                curr2 = curr2.next
                
            if curr1 or curr2:
                curr.next = ListNode()
                curr = curr.next
                
        if carry:
            curr.next = ListNode(carry)
        
        return ans
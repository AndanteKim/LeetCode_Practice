# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack, node = [], head
        
        while node:
            stack.append(node.val)
            node = node.next
            
        doubled, carry = [], 0
        while stack:
            val = stack.pop()
            val = val * 2 + carry
            carry, digit = val // 10, val % 10
            doubled.append(digit)
            
        if carry:
            doubled.append(carry)
        
        sentinel = curr = ListNode()
        
        while doubled:
            curr.next = ListNode(doubled.pop())
            curr = curr.next
        
        return sentinel.next
        
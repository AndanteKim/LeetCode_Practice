# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        list1, list2 = [], []
        
        while l1:
            list1.append(l1.val)
            l1 = l1.next
        
        while l2:
            list2.append(l2.val)
            l2 = l2.next
        
        carry, digit, stack = 0, 0, []
        while list1 or list2:
            v1, v2 = 0, 0
            if list1:
                v1 = list1.pop()
            if list2:
                v2 = list2.pop()
            if carry:
                digit = (v1 + v2 + carry) % 10
                carry = (v1 + v2 + carry) // 10
            else:
                digit = (v1 + v2) % 10
                carry = (v1 + v2) // 10
            stack.append(digit)
        if carry:
            stack.append(carry)
        
        sentinel, root = ListNode(), ListNode()
        sentinel.next = root
        while stack:
            root.val = stack.pop()
            if stack:
                root.next = ListNode()
                root = root.next
        return sentinel.next
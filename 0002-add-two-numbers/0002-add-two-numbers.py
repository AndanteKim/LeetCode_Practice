# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sentinel = ListNode()
        curr, carry = sentinel, 0
        
        while l1 or l2 or carry != 0:
            l1val = l1.val if l1 else 0
            l2val = l2.val if l2 else 0
            
            total = l1val + l2val + carry
            carry = total // 10
            new_node = ListNode(total % 10)
            curr.next = new_node
            curr = new_node
            
            # Move on to next node for each
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            
        return sentinel.next
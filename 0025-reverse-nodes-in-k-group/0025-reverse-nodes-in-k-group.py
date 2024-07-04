# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        sentinel = ListNode()
        sentinel.next, curr = head, head
        stack, prev = [], sentinel
        
        while curr:
            if len(stack) == k:
                prev.next = stack[-1]
                next_node = stack[-1].next
                while len(stack) > 1:
                    node = stack.pop()
                    node.next = stack[-1]
                node = stack.pop()
                prev = node
                node.next = next_node
            
            stack.append(curr)
            curr = curr.next
            
        if len(stack) == k:
            prev.next = stack[-1]
            next_node = stack[-1].next
            while len(stack) > 1:
                node = stack.pop()
                node.next = stack[-1]
            node = stack.pop()
            prev = node
            node.next = next_node
        
        return sentinel.next
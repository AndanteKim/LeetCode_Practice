# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse_LL(self, head: ListNode) -> ListNode:
        prev = None
        
        while head:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
            
        return prev
    
    def plusOne(self, head: ListNode) -> ListNode:
        # Use reverse linked list to flip the digits easily by in-place method
        head = self.reverse_LL(head)
        
        # plus one in advance and set root pointer
        carry, root = 1, head
        
        # Compute the digit plus one with carry
        while root:
            carry, root.val = (root.val + carry) // 10, (root.val + carry) % 10;
            
            # If the root reaches at the end of root and carry is larger than 0, create a new linked list.
            if not root.next and carry > 0:
                root.next = ListNode(carry)
                break
            root = root.next
        
        # Revert the original head and return it.
        return self.reverse_LL(head)
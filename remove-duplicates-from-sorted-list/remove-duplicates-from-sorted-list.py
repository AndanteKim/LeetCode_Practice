# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        root = head
        while head:
            curr = head
            next_node = head.next
            while next_node and curr.val == next_node.val:
                next_node = next_node.next
            curr.next = next_node
            head = head.next
        return root
            
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        if not head.next:
            return head
                
        sentinel = curr = ListNode()
        sentinel.next = head
        
        while curr.next and curr.next.next:
            next_node = curr.next
            temp = next_node.next
            
            next_node.next = temp.next
            temp.next = next_node
            curr.next = temp
            curr = next_node
            
        return sentinel.next
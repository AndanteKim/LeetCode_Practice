# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        curr = odd = head
        even = even_ptr = head.next
        i = 0
        while curr:
            next_node = curr.next
            if i % 2 == 0:
                if odd.next and odd.next.next:
                    odd.next = odd.next.next
                    odd = odd.next
                    
            else:
                if even.next and even.next.next:
                    even.next = even.next.next
                    even = even.next
                else:
                    even.next = None
            
            curr = next_node
            i += 1
        
        odd.next = even_ptr
        
        return head
        
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        even_pt, odd_pt, root = 0, 0, head
        
        while root and root.next:
            even, odd = root.val, root.next.val
            
            if even > odd:
                even_pt += 1
            else:
                odd_pt += 1
            
            root = root.next.next
        
        
        return "Tie" if even_pt == odd_pt else "Odd" if even_pt < odd_pt else "Even"
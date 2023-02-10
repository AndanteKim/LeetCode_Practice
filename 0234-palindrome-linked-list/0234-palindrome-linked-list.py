# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        root = deepcopy(head) 
        curr, prev = head, None
        
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        
        while root:
            if root.val != prev.val:
                return False
            
            root = root.next
            prev = prev.next
        
        return True
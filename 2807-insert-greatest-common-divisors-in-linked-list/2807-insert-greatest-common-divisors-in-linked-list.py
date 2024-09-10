# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def gcd(a: int, b: int) -> int:
            while b > 0:
                a, b = b, a % b
                
            return a
        
        root = head
        while root and root.next:
            temp = root.next
            root.next = ListNode(gcd(max(root.val, root.next.val), min(root.val, root.next.val)), temp)
            root = root.next.next
            
        return head
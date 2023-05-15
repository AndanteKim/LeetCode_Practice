# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        root, n = head, 0
        while root:
            n += 1
            root = root.next
        
        front_node = head
        for _ in range(k - 1):
            front_node = front_node.next
        
        end_node = head
        for _ in range(n - k):
            end_node = end_node.next
        
        front_node.val, end_node.val = end_node.val, front_node.val
        
        return head
        
        
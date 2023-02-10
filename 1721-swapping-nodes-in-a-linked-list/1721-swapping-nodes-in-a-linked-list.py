# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        currNode = frontNode = endNode = head
        length = 0
        
        while currNode:
            length += 1
            if length == k:
                frontNode = currNode
            currNode = currNode.next
        
        endNode = head
        for i in range(length - k):
            endNode = endNode.next
        
        frontNode.val, endNode.val = endNode.val, frontNode.val
        
        return head
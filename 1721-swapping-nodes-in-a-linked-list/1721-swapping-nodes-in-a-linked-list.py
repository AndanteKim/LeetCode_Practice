# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        length = 0
        frontNode = endNode = None
        currNode = head
        
        while currNode:
            length += 1
            if endNode != None:
                endNode = endNode.next
            
            if length == k:
                frontNode = currNode
                endNode = head
            
            currNode = currNode.next
        
        frontNode.val, endNode.val = endNode.val, frontNode.val
        
        return head
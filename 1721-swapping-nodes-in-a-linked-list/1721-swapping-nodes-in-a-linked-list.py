# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapListNodesToNext(self, prevOfFirstK: Optional[ListNode], prevOfLastK: Optional[ListNode]) -> None:
        if prevOfLastK.next == prevOfFirstK:
            self.swapListNodesToNext(prevOfLastK, prevOfFirstK)
        elif prevOfFirstK.next == prevOfLastK:
            prevOfFirstK.next = prevOfLastK.next
            prevOfLastK.next = prevOfFirstK.next.next
            prevOfFirstK.next.next = prevOfLastK
        else:
            tempLeftNextNext = prevOfFirstK.next.next
            tempRightNextNext = prevOfLastK.next.next
            
            tempLeftNext = prevOfFirstK.next
            prevOfFirstK.next = prevOfLastK.next
            prevOfFirstK.next.next = tempLeftNextNext
            
            prevOfLastK.next = tempLeftNext
            prevOfLastK.next.next = tempRightNextNext
    
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        sentinel = ListNode(-1)
        sentinel.next = head
        last = sentinel
        
        for i in range(k-1):
            last = last.next
        
        prevOfFirstK = last
        
        prevOfLastK = sentinel
        
        while last.next.next != None:
            last = last.next
            prevOfLastK = prevOfLastK.next
        
        self.swapListNodesToNext(prevOfFirstK, prevOfLastK)
        
        return sentinel.next
        
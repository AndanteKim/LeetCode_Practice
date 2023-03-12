# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        
        for i in range(len(lists)):
            if lists[i]:
                heappush(heap, (lists[i].val, i))
                
        dummy = ListNode(0)
        curr = dummy
        
        while heap:
            val, idx = heappop(heap)
            curr.next = lists[idx]
            curr = curr.next
            
            if lists[idx].next:
                lists[idx] = lists[idx].next
                heappush(heap, (lists[idx].val, idx))
        
        return dummy.next
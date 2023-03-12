# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        
        merged_arr = []
        for l in lists:
            while l:
                merged_arr.append(l.val)
                l = l.next
        
        if not merged_arr:
            return None
        
        merged_arr.sort()
        sentinel = ListNode()
        merged_LL = ListNode(merged_arr[0])
        sentinel.next = merged_LL
        for elem in merged_arr[1:]:
            merged_LL.next = ListNode(elem)
            merged_LL = merged_LL.next
        
        return sentinel.next

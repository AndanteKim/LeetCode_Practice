# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        nodes = []
        head = point = ListNode()
        
        for l in lists:
            while l:
                nodes.append(l.val)
                l = l.next
                
        for x in sorted(nodes):
            point.next = ListNode(x)
            point = point.next

        return head.next
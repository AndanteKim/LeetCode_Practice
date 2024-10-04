# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Base case
        if not list1:
            return list2
        
        if not list2:
            return list1
        
        ans = None
        if list1.val <= list2.val:
            ans = list1
            list1.next = self.mergeTwoLists(list1.next, list2)
        else:
            ans = list2
            list2.next = self.mergeTwoLists(list1, list2.next)
        
        return ans
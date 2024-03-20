# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1, a: int, b: int, list2) -> ListNode:
        # Without sentinel or dummy
        curr, count = list1, 1
        
        while count < a:
            curr = curr.next
            count += 1
        
        insert_after = curr
        while count < b + 1:
            curr = curr.next
            count += 1
        
        insert_after.next = list2
        while list2:
            prev = list2
            list2 = list2.next
        prev.next = curr.next
        return list1
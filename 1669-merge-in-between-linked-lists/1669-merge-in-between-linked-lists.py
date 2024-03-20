# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        sentinel, l2 = ListNode(), list2
        sentinel.next = list1
        root, curr = sentinel, -1
        
        while root:
            if curr == a - 1:
                temp = root.next
                root.next = list2
                root = temp
                
            if curr == b:
                while l2.next:
                    l2 = l2.next
                l2.next = root
                
            root = root.next
            curr += 1
            
        return sentinel.next
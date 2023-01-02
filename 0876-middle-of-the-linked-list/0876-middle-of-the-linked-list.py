# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        length, find_half = 0, 0
        pre_explore = head
        while pre_explore != None:
            length += 1
            pre_explore = pre_explore.next
        while head != None:
            if find_half == length // 2:
                return head
            find_half += 1
            head = head.next
        return None
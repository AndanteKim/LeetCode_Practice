# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        need_delete, sentinel = set(nums), ListNode()
        sentinel.next = head
        curr = sentinel

        while curr:
            while curr.next and curr.next.val in need_delete:
                curr.next = curr.next.next
            curr = curr.next

        return sentinel.next
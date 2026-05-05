# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not (head and head.next) or k == 0:
            return head

        n, curr = 0, head

        while curr:
            curr = curr.next
            n += 1

        if k % n == 0:
            return head

        sentinel = ListNode(0)
        sentinel.next = head
        curr = sentinel
        for _ in range(n - (k % n)):
            curr = curr.next

        root = leftover = curr.next
        curr.next = None

        while leftover and leftover.next:
            leftover = leftover.next
        
        if leftover:
            leftover.next = head

        return root
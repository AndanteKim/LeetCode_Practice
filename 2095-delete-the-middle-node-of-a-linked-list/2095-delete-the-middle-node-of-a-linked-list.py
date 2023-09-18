# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n, root = 0, head
        while root:
            n += 1
            root = root.next
        if n == 1:
            return None
        i, mid, root = 0, n // 2, head
        while root and root.next:
            i += 1
            if i == mid:
                root.next = root.next.next
            root = root.next
        return head
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        seen = set()
        root = head
        while root and root.next:
            if root not in seen:
                seen.add(root)
            else:
                return root
            root = root.next
        return None
        
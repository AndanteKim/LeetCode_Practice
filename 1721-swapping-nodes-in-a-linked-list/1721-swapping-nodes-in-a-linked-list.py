# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        root, n = head, 0
        while root:
            n += 1
            root = root.next
        
        root, kth, n_kth, i = head, -1, -1, 1
        while root:
            if i == k:
                kth = root.val
            if i == n - k + 1:
                n_kth = root.val
            root = root.next
            i += 1
        
        root, i = head, 1
        while root:
            if i == k:
                root.val = n_kth
            if i == n - k + 1:
                root.val = kth
            root = root.next
            i += 1
            
        return head 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def _reorderList(self, root: Optional[ListNode], curr: Optional[ListNode]) -> ListNode:
        if not curr:
            return root
        
        # Keep on passing the initial root to the end
        root = self._reorderList(root, curr.next)
        
        if not root:
            return None
        
        """
        We stop reconfiguring in 2 cases.
        1. returned new root is same as head: Odd number of list items, so we have come to the middle
        2. returned new root's next is same as head" Even number of list items
        """
        temp = None
        if root == curr or root.next == curr:
            curr.next = None
        else:
            # Make returned root's next to be curr and return root's next as the new root
            temp = root.next
            root.next = curr
            curr.next = temp
        
        return temp
    
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        
        self._reorderList(head, head.next)
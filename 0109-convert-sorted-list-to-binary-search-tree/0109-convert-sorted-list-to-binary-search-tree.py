# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSize(self, head):
            ptr, c = head, 0
            
            while ptr:
                ptr = ptr.next
                c += 1
            return c
        
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        size = self.findSize(head)
        def convert(left: int, right: int) -> Optional[TreeNode]:
            nonlocal head
            if left > right:
                return None
            mid = (left + right) >> 1
            left = convert(left, mid - 1)
            
            node = TreeNode(head.val)
            node.left = left
            head = head.next
            
            node.right = convert(mid + 1, right)
            return node
        return convert(0, size - 1)
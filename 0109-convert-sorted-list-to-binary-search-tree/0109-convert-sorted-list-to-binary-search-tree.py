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
        ptr = head
        c = 0
        while ptr:
            ptr = ptr.next
            c += 1
        return c
    
    def convert(self, left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None
        mid = (left + right) >> 1
        left = self.convert(left, mid - 1)
        node = TreeNode(self.head.val)
        node.left = left
        self.head = self.head.next
        
        node.right = self.convert(mid + 1, right)
        return node
    
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        size = self.findSize(head)
        self.head = head;
        return self.convert(0, size - 1)
        
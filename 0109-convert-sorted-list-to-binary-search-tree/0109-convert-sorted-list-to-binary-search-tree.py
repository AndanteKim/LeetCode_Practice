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
    def mapListToValues(self, head: Optional[ListNode]) -> List[int]:
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        return vals
    
    def convertListToBST(self, values: List[int], left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None
        
        mid = (left + right) >> 1
        node = TreeNode(values[mid])
        
        if left == right:
            return node
        
        node.left = self.convertListToBST(values, left, mid - 1)
        node.right = self.convertListToBST(values, mid + 1, right)
        return node
    
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        values = self.mapListToValues(head)
        
        return self.convertListToBST(values, 0, len(values) - 1)
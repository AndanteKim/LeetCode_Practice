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
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        if not root:
            return False
        
        # Check the current node and all its descendants
        main = self.dfs(root, head)
        
        # Check all paths from the left and right children of the root
        left = self.isSubPath(head, root.left)
        right = self.isSubPath(head, root.right)
        
        return main or left or right
    
    def dfs(self, node: TreeNode, head: ListNode) -> bool:
        if not head:
            return True
        
        if not node or node.val != head.val:
            return False
        
        # Continue searching in both left and right subtrees
        left = self.dfs(node.left, head.next)
        right = self.dfs(node.right, head.next)
        
        return left or right
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
        def dfs(curr_t: TreeNode, curr_l: ListNode) -> bool:
            if not curr_l:
                return True
            
            if (not curr_t and curr_l) or curr_t.val != curr_l.val:
                return False
            left = dfs(curr_t.left, curr_l.next)
            right = dfs(curr_t.right, curr_l.next)
            
            return left or right
        
        queue = deque([root])
        while queue:
            curr_tree = queue.popleft()
            
            if curr_tree.val == head.val:
                is_subpath = dfs(curr_tree, head)
                if is_subpath:
                    return True
            
            if curr_tree.left:
                queue.append(curr_tree.left)
                
            if curr_tree.right:
                queue.append(curr_tree.right)
                
        return False
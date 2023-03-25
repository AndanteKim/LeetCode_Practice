# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        
        queue = deque([root])
        
        while queue:
            q = queue.popleft()
            if not q.left and val < q.val:
                q.left = TreeNode(val)
                break
            if not q.right and val > q.val:
                q.right = TreeNode(val)
                break
            
            if q.left and val < q.val:
                queue.append(q.left)
            
            if q.right and val > q.val:
                queue.append(q.right)
        
        return root
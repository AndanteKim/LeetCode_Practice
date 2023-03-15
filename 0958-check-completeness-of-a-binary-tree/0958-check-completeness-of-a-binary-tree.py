# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        queue, nullNodeFound = deque([root]), False
        
        while queue:
            node = queue.popleft()
            
            if not node:
                nullNodeFound = True
            else:
                if nullNodeFound:
                    return False
                queue.append(node.left)
                queue.append(node.right)
                
        return True
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        bfs, is_odd = deque([(None, root)]), False
        
        while bfs:
            n, stack = len(bfs), []
            
            if is_odd:
                for _ in range(n):
                    parent, child = bfs.popleft()
                    stack.append(child.val)
                    bfs.append((parent, child))
                
                while stack:
                    parent, child = bfs.popleft()
                    child.val = stack.pop()
                    bfs.append((parent, child))
                
            for _ in range(n):
                parent, child = bfs.popleft()
                
                if child.left and child.right:
                    bfs.append((child, child.left))
                    bfs.append((child, child.right))
                
            is_odd = not is_odd
        
        return root
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        
        queue = deque([(root, 0)])
        while queue:
            sz, stack = len(queue), []
            
            for _ in range(sz):
                node, level = queue.popleft()
                
                if level % 2 == 0:
                    if node.val % 2 == 0 or (stack and node.val - stack[-1] <= 0):
                        return False
                    else:
                        stack.append(node.val)
                else:
                    if node.val % 2 == 1 or (stack and node.val - stack[-1] >= 0):
                        return False
                    else:
                        stack.append(node.val)
                
                if node.left:
                    queue.append((node.left, level + 1))
                
                if node.right:
                    queue.append((node.right, level + 1))
        
        
        return True
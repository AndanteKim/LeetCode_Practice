# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        
        ans, queue = 0, deque([(root, None, 0)])
        
        # True: right, False: left
        while queue:
            node, direction, length = queue.popleft()
            
            ans = max(ans, length)
            length += 1
            
            if node.left:
                if direction == None or direction == True:
                    queue.append((node.left, False, length))
                else:
                    queue.append((node.left, False, 1))
            
            if node.right:
                if direction == None or direction == False:
                    queue.append((node.right, True, length))
                else:
                    queue.append((node.right, True, 1))
            
        return ans
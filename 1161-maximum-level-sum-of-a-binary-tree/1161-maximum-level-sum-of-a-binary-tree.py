# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        ans, max_sum = -1, float('-inf')
        queue = deque([(root, 1)])
        
        while queue:
            
            total, curr_level = 0, -1
            for _ in range(len(queue)):
                node, level = queue.popleft()
                total += node.val
                curr_level = level
                
                if node.left:
                    queue.append((node.left, level + 1))
                    
                if node.right:
                    queue.append((node.right, level + 1))
            if max_sum < total:
                max_sum = total
                ans = curr_level
            
        
        return ans
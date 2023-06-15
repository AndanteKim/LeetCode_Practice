# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        
        queue, max_sum, ans = deque([(root, 1)]), float('-inf'), 1
        while queue:
            curr_sum, q_length = 0, len(queue)
            
            for _ in range(q_length):
                node, level = queue.popleft()
                curr_sum += node.val
                
                if node.left:
                    queue.append((node.left, level + 1))
                
                if node.right:
                    queue.append((node.right, level + 1))
            
            if max_sum < curr_sum:
                max_sum = curr_sum
                ans = level
        
        return ans
                
                
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        level_sum = defaultdict(int)
        queue, max_level = deque([(root, 0)]), 0
        
        while queue:
            q, level = queue.popleft()
            max_level = max(max_level, level)
            level_sum[level] += q.val
            
            if q.left:
                queue.append((q.left, level + 1))
            
            if q.right:
                queue.append((q.right, level + 1))
        
        return level_sum[max_level]
        
        
        
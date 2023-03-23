# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        queue, ans = deque([root]), list()
        
        while queue:
            level = len(queue)
            max_num_each_level = float('-inf')
            for _ in range(level):
                q = queue.popleft()
                max_num_each_level = max(max_num_each_level, q.val)
                if q.left:
                    queue.append(q.left)
                
                if q.right:
                    queue.append(q.right)
            ans.append(max_num_each_level)
        return ans
                
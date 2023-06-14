# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        
        queue, flatten, ans = deque([root]), [], float('inf')
        
        while queue:
            curr = queue.popleft()
            flatten.append(curr.val)
            
            if curr.left:
                queue.append(curr.left)
            
            if curr.right:
                queue.append(curr.right)
                
        flatten.sort()
        for i in range(len(flatten) - 1):
            ans = min(ans, flatten[i + 1] - flatten[i])
        
        return ans
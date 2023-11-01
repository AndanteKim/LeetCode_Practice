# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        frequencies, ans = dict(), []
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            
            frequencies[node.val] = frequencies.get(node.val, 0) + 1
            
            if node.left:
                queue.append(node.left)
            
            if node.right:
                queue.append(node.right)
                
        mx = max(frequencies.values())
        for val, cnt in frequencies.items():
            if cnt == mx:
                ans.append(val)
        
        return ans
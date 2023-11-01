# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node: Optional[TreeNode], values: List[int]) -> None:
            if not node:
                return
            
            # Inorder traversal visits nodes in sorted order
            dfs(node.left, values)
            values.append(node.val)
            dfs(node.right, values)
        
        values = []
        dfs(root, values)
        
        max_streak, curr_streak, curr_num = 0, 0, 0
        ans = []
        
        for num in values:
            if num == curr_num:
                curr_streak += 1
            else:
                curr_streak = 1
                curr_num = num
            
            if curr_streak > max_streak:
                ans = []
                max_streak = curr_streak
            
            if curr_streak == max_streak:
                ans.append(num)
        
        return ans
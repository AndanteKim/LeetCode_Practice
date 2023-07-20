# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], parent_robbed: bool, memo: [Optional[TreeNode], int], not_memo: [Optional[TreeNode], int]) -> int:
        if not node:
            return 0
        if parent_robbed:
            if node in memo:
                return memo[node]
            result = self.dfs(node.left, False, memo, not_memo) + self.dfs(node.right, False, memo, not_memo)
            memo[node] = result
        else:
            if node in not_memo:
                return not_memo[node]
            rob = node.val + self.dfs(node.left, True, memo, not_memo) + self.dfs(node.right, True, memo, not_memo)
            not_rob = self.dfs(node.left, False, memo, not_memo) + self.dfs(node.right, False, memo, not_memo)
            result = max(rob, not_rob)
            not_memo[node] = result
            
        return result
    
    def rob(self, root: Optional[TreeNode]) -> int:
        memo, not_memo = dict(), dict()
        return self.dfs(root, False, memo, not_memo)
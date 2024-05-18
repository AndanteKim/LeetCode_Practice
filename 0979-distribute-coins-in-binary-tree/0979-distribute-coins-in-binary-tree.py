# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        def dfs(curr: Optional[TreeNode]) -> int:
            nonlocal ans
            # base case
            if not curr:
                return 0
            
            # Calculate the coins each subtree has available to exchange
            left_coins = dfs(curr.left)
            right_coins = dfs(curr.right)
            
            # Add the total number of exchanges to move
            ans += abs(left_coins) + abs(right_coins)
            
            # The number of coins current has available to exchange
            return curr.val - 1 + left_coins + right_coins
        
        ans = 0
        dfs(root)
        return ans
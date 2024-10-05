# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        dp = [[[] for _ in range(n + 1)] for _ in range(n + 1)]
        
        for i in range(n + 1):
            dp[i][i] = [TreeNode(i)]
            
        for num_of_nodes in range(2, n + 1):
            for start in range(1, n - num_of_nodes + 2):
                end = start + num_of_nodes - 1
                for i in range(start, end + 1):
                    left_subtrees = dp[start][i - 1] if i != start else [None]
                    right_subtrees = dp[i + 1][end] if i != end else [None]
                    
                    for left in left_subtrees:
                        for right in right_subtrees:
                            root = TreeNode(i, left, right)
                            dp[start][end].append(root)
        
        return dp[1][n]
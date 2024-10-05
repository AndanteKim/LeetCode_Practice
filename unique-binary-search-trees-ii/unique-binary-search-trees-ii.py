# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def clone(self, node: 'TreeNode', offset: int) -> 'TreeNode':
        # Base case
        if not node:
            return None
        
        cloned_node = TreeNode(node.val + offset)
        cloned_node.left = self.clone(node.left, offset)
        cloned_node.right = self.clone(node.right, offset)
        return cloned_node
    
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        dp = [[] for _ in range(n + 1)]
        dp[0].append(None)
        
        for number_of_nodes in range(1, n + 1):
            for i in range(1, number_of_nodes + 1):
                j = number_of_nodes - i
                
                for left in dp[i - 1]:
                    for right in dp[j]:
                        root = TreeNode(i, left, self.clone(right, i))
                        dp[number_of_nodes].append(root)
                        
        return dp[n]
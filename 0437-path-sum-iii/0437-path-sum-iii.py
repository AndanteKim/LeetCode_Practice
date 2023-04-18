# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorder(self, node: Optional[TreeNode], curr_sum: int) -> None:
        if not node:
            return
        
        curr_sum += node.val
        
        if curr_sum == self.targetSum:
            self.count += 1
        
        self.count += self.h[curr_sum - self.targetSum]
        self.h[curr_sum] += 1
        
        self.preorder(node.left, curr_sum)
        self.preorder(node.right, curr_sum)
        
        self.h[curr_sum] -= 1
    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.count, self.targetSum = 0, targetSum
        self.h = defaultdict(int)
        self.preorder(root, 0)
        return self.count
        
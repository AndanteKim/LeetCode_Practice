# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def average(self, t: Optional[TreeNode], i: int, total: List[float], count: List[int]) -> None:
        if not t:
            return
        
        if i < len(total):
            total[i] += t.val
            count[i] += 1
        else:
            total.append(t.val)
            count.append(1)
        
        self.average(t.left, i + 1, total, count)
        self.average(t.right, i + 1, total, count)
    
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        count, res = [], []
        self.average(root, 0, res, count)
        for i in range(len(res)):
            res[i] /= count[i]
        return res
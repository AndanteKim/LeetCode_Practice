# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root: return False
        
        curr, m, result = root, 0, False
        
        while curr:
            if not curr.left:
                m += curr.val
                curr = curr.right
                if not curr and m == targetSum:
                    return True
            else:
                pred = curr.left
                n = pred.val
                
                while pred.right and pred.right != curr:
                    pred = pred.right
                    n += pred.val
                    
                if not pred.right:
                    pred.right = curr
                    m += curr.val
                    if not pred.left and m + n == targetSum:
                        return True
                    curr = curr.left
                else:
                    pred.right = None
                    m -= n
                    curr = curr.right
        return result
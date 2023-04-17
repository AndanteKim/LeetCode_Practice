# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recurseTree(self, node: Optional[TreeNode], remainingSum: int, pathNodes: List[int],
                    ans: List[List[int]]) -> None:
        if not node:
            return
        
        pathNodes.append(node.val)
        
        if remainingSum == node.val and not node.left and not node.right:
            ans.append(list(pathNodes))
        else:
            self.recurseTree(node.left, remainingSum - node.val, pathNodes, ans)
            self.recurseTree(node.right, remainingSum - node.val, pathNodes, ans)
        
        pathNodes.pop();   
    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        self.recurseTree(root, targetSum, [], ans)
        return ans
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleBST(self, start: int, end: int, memo: Dict[Tuple[int], int]) -> List[Optional[TreeNode]]:
        ans = []
        if start > end:
            ans.append(None)
            return ans
        
        if (start, end) in memo:
            return memo[(start, end)]
        
        # Iterate through all values from start to end to construct left and right subtree recursively
        for i in range(start, end + 1):
            leftSubTrees = self.allPossibleBST(start, i - 1, memo)
            rightSubTrees = self.allPossibleBST(i + 1, end, memo)
            
            for left in leftSubTrees:
                for right in rightSubTrees:
                    root = TreeNode(i, left, right)
                    ans.append(root)
        
        memo[(start, end)] = ans
        return ans
    
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        memo = dict()
        return self.allPossibleBST(1, n, memo)
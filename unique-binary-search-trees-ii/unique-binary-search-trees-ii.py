# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def all_possible_bst(self, start: int, end: int, memo: Dict[int, int]) -> List['TreeNode']:
        ans = []
        if start > end:
            ans.append(None)
            return ans
        
        if (start, end) in memo:
            return memo[(start, end)]
        
        # Iterate through all values from start to end to construct left and right subtree recursively.
        for i in range(start, end + 1):
            left_subtrees = self.all_possible_bst(start, i - 1, memo)
            right_subtrees = self.all_possible_bst(i + 1, end, memo)
            
            # Loop through all left and right subtrees and connect them to ith root.
            for left in left_subtrees:
                for right in right_subtrees:
                    root = TreeNode(i, left, right)
                    ans.append(root)
                    
        memo[(start, end)] = ans
        return ans
                    
    
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        memo = dict()
        return self.all_possible_bst(1, n, memo)
        
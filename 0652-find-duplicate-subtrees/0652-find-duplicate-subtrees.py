# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    cnt = defaultdict(int)
    res = []
    def traverse(self, node: Optional[TreeNode]) -> str:
        if not node:
            return ""
        representation = ("(" + self.traverse(node.left) + ")" + str(node.val)\
                         + "(" + self.traverse(node.right) + ")")
        self.cnt[representation] += 1
        if self.cnt[representation] == 2:
            self.res.append(node)
        return representation
        
    
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.cnt = defaultdict(int)
        self.res = []
        self.traverse(root)
        return self.res
        
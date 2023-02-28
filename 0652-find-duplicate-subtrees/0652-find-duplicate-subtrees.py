# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    triplet_to_id = dict()
    cnt = defaultdict(int)
    res = []
    def traverse(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0
        triplet = (self.traverse(node.left), node.val, self.traverse(node.right))
        if triplet not in self.triplet_to_id:
            self.triplet_to_id[triplet] = len(self.triplet_to_id) + 1
        id = self.triplet_to_id[triplet]
        self.cnt[id] += 1
        if self.cnt[id] == 2:
            self.res.append(node)
        return id
    
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.triplet_to_id = dict()
        self.cnt = defaultdict(int)
        self.res = []
        self.traverse(root)
        return self.res
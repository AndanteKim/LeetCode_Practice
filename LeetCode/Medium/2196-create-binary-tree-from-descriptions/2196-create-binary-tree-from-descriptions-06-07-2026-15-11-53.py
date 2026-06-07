# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        ancestors, ans = defaultdict(int), None
        load = defaultdict()
        for parent, child, is_left in descriptions:
            p, c = None, None
            if parent in load:
                p = load[parent]
            else:
                p = TreeNode(parent)
                load[parent] = p
            
            if child in load:
                c = load[child]
            else:
                c = TreeNode(child)
                load[child] = c
            
            if is_left:
                p.left = c
            else:
                p.right = c
            
            ancestors[child] = parent

        for node in load:
            if node not in ancestors:
                ans = load[node]
                break

        return ans
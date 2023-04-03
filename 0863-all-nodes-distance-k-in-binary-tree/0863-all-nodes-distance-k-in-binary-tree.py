# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node: TreeNode, ans: List[int], target: TreeNode) -> int:
        if not node:
            return -1
        elif node == target:
            self.subtree_add(node, 0, ans)
            return 1
        else:
            L, R = self.dfs(node.left, ans, target), self.dfs(node.right, ans, target)
            if L != -1:
                if L == self.k:
                    ans.append(node.val)
                self.subtree_add(node.right, L + 1, ans)
                return L + 1
            elif R != -1:
                if R == self.k:
                    ans.append(node.val)
                self.subtree_add(node.left, R + 1, ans)
                return R + 1
            else:
                return -1
            
    def subtree_add(self, node: TreeNode, dist: int, ans: List[int]) -> None:
        if not node:
            return
        elif dist == self.k:
            ans.append(node.val)
        else:
            self.subtree_add(node.left, dist + 1, ans)
            self.subtree_add(node.right, dist + 1, ans)
    
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        ans = []
        self.k = k
        self.dfs(root, ans, target)
        
        return ans
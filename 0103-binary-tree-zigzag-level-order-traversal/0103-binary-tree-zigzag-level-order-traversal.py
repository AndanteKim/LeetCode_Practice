# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return root
        
        ans = []
        
        def dfs(node, level):
            if level >= len(ans):
                ans.append(deque([node.val]))
            else:
                if level % 2 == 0:
                    ans[level].append(node.val)
                else:
                    ans[level].appendleft(node.val)
        
            for next_node in [node.left, node.right]:
                if next_node is not None:
                    dfs(next_node, level + 1)
        
        dfs(root, 0)
        return ans
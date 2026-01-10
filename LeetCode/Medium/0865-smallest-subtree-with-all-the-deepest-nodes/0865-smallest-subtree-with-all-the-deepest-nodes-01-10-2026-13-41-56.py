# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node: Optional[TreeNode], parent: Optional[TreeNode] = None) -> None:
            if not node:
                return

            depth[node] = depth[parent] + 1
            dfs(node.left, node)
            dfs(node.right, node)
        
        # Tag each node with its depth.
        depth = {None: -1}
        dfs(root)
        max_depth = max(depth.values())

        def find_ans(node: Optional[TreeNode]) -> Optional[TreeNode]:
            # Return the answer for the subtree at node.
            if not node or depth.get(node, None) == max_depth:
                return node

            L, R = find_ans(node.left), find_ans(node.right)

            return node if L and R else L or R
        
        return find_ans(root)
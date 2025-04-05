# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bfs(self, root: Optional[TreeNode]) -> List[List[Tuple[int]]]:
        q_tree = deque([root])
        depth, tree_set = 0,[]
        
        while q_tree:
            inter_set = []
            for i in range(len(q_tree)):
                curr = q_tree.popleft()
                inter_set.append((depth, curr.val))
                if curr.left:
                    q_tree.append(curr.left)
                
                if curr.right:
                    q_tree.append(curr.right)
            tree_set.append(inter_set)
            depth += 1
        
        return tree_set[-1]

    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def lca(node: Optional[TreeNode], a: int, b: int) -> Optional[TreeNode]:
            if not node or node.val == a or node.val == b:
                return node
            left = lca(node.left, a, b)
            right = lca(node.right, a, b)

            if not left:
                return right
            elif not right:
                return left
            return node
        
        last_set = self.bfs(root)
        
        a, b = last_set[0][1], last_set[-1][1]
        return lca(root, a, b)
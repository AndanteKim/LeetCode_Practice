# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random

class Solution:
    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        def dfs(node: 'Optional[Node]') -> 'Optional[NodeCopy]':
            if not node:
                return

            if node in seen:
                return seen[node]
            
            seen[node] = NodeCopy(node.val)
            seen[node].left = dfs(node.left)
            seen[node].right = dfs(node.right)
            seen[node].random = dfs(node.random)

            return seen[node]

        seen = dict()
        return dfs(root)
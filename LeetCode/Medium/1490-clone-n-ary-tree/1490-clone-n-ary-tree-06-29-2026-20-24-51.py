"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        def dfs(node: 'Node') -> 'Node':
            if not node:
                return None

            new_node = Node(node.val)
            new_node.children = [dfs(child) for child in node.children]
            return new_node

        return dfs(root)
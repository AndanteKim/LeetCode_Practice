"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        def dfs(node: 'Node') -> None:
            """
            Performs standard inorder traversal:
            left -> node -> right
            and links all nodes into DLL
            """
            nonlocal last, first
            if node:
                # left
                dfs(node.left)

                # node
                if last:
                    # link the previous node (last)
                    # with the current one (node)
                    last.right = node
                    node.left = last
                else:
                    # keep the smallest node
                    # to close DLL later on
                    first = node
                last = node

                # right
                dfs(node.right)
        
        if not root:
            return None

        # the smallest (first) and the largest (last) nodes
        first, last = None, None
        dfs(root)

        # close DLL
        last.right = first
        first.left = last

        return first
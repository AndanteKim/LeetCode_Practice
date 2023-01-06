"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root: return []
        queue, ans = deque([root]), []
        
        while queue:
            q = queue.pop()
            ans.append(q.val)
            while q.children:
                branch = q.children.pop()
                queue.append(branch)
                
        return ans
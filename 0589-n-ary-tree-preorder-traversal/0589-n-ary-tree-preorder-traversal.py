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
        stack, ans = [root], []
        
        while stack:
            q = stack.pop()
            ans.append(q.val)
            while q.children:
                stack.append(q.children.pop())
                
        return ans
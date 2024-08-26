"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        def dfs(curr: 'Node') -> List[int]:
            if not curr:
                return []
            
            ans = []
            for child in curr.children:
                ans += dfs(child)
            
            ans.append(curr.val)
            return ans
        
        
        return dfs(root)
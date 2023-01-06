"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        def dfs(root = root, ans = ans):
            if not root:
                return
            else:
                ans.append(root.val)
                
                for child in root.children:
                    dfs(child, ans)
        
        dfs()
        return ans
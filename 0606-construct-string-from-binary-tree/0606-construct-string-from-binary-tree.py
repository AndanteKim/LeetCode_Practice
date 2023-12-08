# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if not root:
            return ""
        stack, ans, visited = [root], "", set()
        
        while stack:
            node = stack[-1]
            if node in visited:
                stack.pop()
                ans += ')'
            else:
                visited.add(node)
                ans += '(' + str(node.val)
                if not node.left and node.right:
                    ans += "()"
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left)
            
        return ans[1:-1]
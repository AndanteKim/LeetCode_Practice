# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        ans, queue = "", deque([(root, "")])
        
        while queue:
            node, curr = queue.popleft()
            curr += chr(node.val + 97)
            
            # If it's leaf
            if not (node.left or node.right):
                rev = curr[::-1]
                if not ans or ans > rev:
                    ans = rev
            
            if node.left:
                queue.append((node.left, curr))
            
            if node.right:
                queue.append((node.right, curr))
                
        return ans
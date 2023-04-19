# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans, queue = [], deque([(root, 0)])
        
        while queue:
            curr = []
            for _ in range(len(queue)):
                node, level = queue.popleft()
                curr.append(node.val)
            
                if node.left:
                    queue.append((node.left, level + 1))
            
                if node.right:
                    queue.append((node.right, level + 1))
            ans.append(curr)
        
        return ans
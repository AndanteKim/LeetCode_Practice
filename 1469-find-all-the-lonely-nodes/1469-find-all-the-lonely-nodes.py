# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        queue, ans = deque([root]), []
        
        while queue:
            curr = queue.popleft()
            
            # If child is leaf
            if (curr.left is not None) ^ (curr.right is not None):
                # If its child is leaf
                if curr.left:
                    ans.append(curr.left.val)
                
                if curr.right:
                    ans.append(curr.right.val)
            
            if curr.left:
                queue.append(curr.left)
            
            if curr.right:
                queue.append(curr.right)
                
        return ans
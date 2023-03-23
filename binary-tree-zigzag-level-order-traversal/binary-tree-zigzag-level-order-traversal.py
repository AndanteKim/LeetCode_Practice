# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        queue, ans = deque([root]), []
        reverse = False
        
        while queue:
            bfs = []
            if not reverse:
                for _ in range(len(queue)):
                    q = queue.popleft()
                    bfs.append(q.val)
                    if q.left:
                        queue.append(q.left)
                
                    if q.right:
                        queue.append(q.right)
                reverse = True
            
            else:
                for _ in range(len(queue)):
                    q = queue.pop()
                    bfs.append(q.val)
                    
                    if q.right:
                        queue.appendleft(q.right)
                    
                    if q.left:
                        queue.appendleft(q.left)  
                reverse = False
            ans.append(bfs)
        return ans
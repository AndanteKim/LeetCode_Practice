# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bfs(self, root: Optional[TreeNode]) -> Dict[TreeNode, TreeNode]:
        ancestors, queue = dict(), deque([(root, None)])
        
        while queue:
            child, parent = queue.popleft()
            
            ancestors[child] = parent
            
            if child.left:
                queue.append((child.left, child))
                
            if child.right:
                queue.append((child.right, child))
                
        return ancestors
    
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        ancestors, ans = self.bfs(root), ""
        queue, start, dest = deque([root]), None, None
        while queue:
            curr = queue.popleft()
                
            if curr.val == startValue:
                start = curr
                break
            
            if curr.left:
                queue.append(curr.left)
                
            if curr.right:
                queue.append(curr.right)
        
        curr_point, seen = "", {start.val}
        while start:
            queue = deque([(start, curr_point)])
            
            while queue:
                curr, status = queue.popleft()
                
                if curr.val == destValue:
                    return status
                
                if curr.left and curr.left.val not in seen:
                    queue.append((curr.left, status + 'L'))
                    seen.add((curr.left.val))
                    
                if curr.right and curr.right.val not in seen:
                    queue.append((curr.right, status + 'R'))
                    seen.add((curr.right.val))
                
            curr_point += 'U'
            start = ancestors[start]
            
        return ""
        
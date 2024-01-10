# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        adj = defaultdict(list)
        queue = deque([root])
        while queue:
            node = queue.popleft()
            
            if node.left:
                adj[node.val].append(node.left.val)
                adj[node.left.val].append(node.val)
                queue.append(node.left)
            
            if node.right:
                adj[node.val].append(node.right.val)
                adj[node.right.val].append(node.val)
                queue.append(node.right)
        
        visited, ans = [False] * (10 ** 5 + 1), 0
        queue.append((start, 0))
        
        while queue:
            node, dist = queue.popleft()
            
            if not visited[node]:
                ans = max(ans, dist)
                visited[node] = True
                for neighbor in adj[node]:
                    queue.append((neighbor, dist + 1))
        
        return ans
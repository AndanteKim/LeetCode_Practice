# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        if k == 0:
            return [target.val]
        
        graph, ans = defaultdict(list), []
        
        queue = deque([(root, None)])
        while queue:
            node, parent = queue.popleft()
            graph[node].append(parent)
            graph[parent].append(node)
            
            if node.left:
                queue.append((node.left, node))
            if node.right:
                queue.append((node.right, node))
        
        queue, visited = deque([(target, 0)]), set([target.val])
        while queue:
            node, level = queue.popleft()
            if level == k:
                ans.append(node.val)
                continue
            
            for neighbor in graph[node]:
                if neighbor and neighbor.val not in visited:
                    visited.add(neighbor.val)
                    queue.append((neighbor, level + 1))
        
        return ans
        
        
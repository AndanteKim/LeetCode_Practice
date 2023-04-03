# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node: TreeNode, parent: TreeNode) -> None:
        if not node:
            return
        
        node.parent = parent
        self.dfs(node.left, node)
        self.dfs(node.right, node)
    
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        self.dfs(root, None)
        queue, seen, distance = deque([target]), {target}, 0
        
        while queue and distance < k:
            curr_length = len(queue)
            for _ in range(curr_length):
                node = queue.popleft()
                for neighbor in [node.left, node.right, node.parent]:
                    if neighbor and neighbor not in seen:
                        seen.add(neighbor)
                        queue.append(neighbor)
            distance += 1
        return [node.val for node in queue]
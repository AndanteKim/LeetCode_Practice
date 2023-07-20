# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        tree = []
        graph, index = {-1: []}, -1
        queue = deque([(root, -1)])
        while queue:
            node, parent_idx = queue.popleft()
            if node:
                index += 1
                tree.append(node.val)
                graph[index] = []
                graph[parent_idx].append(index)
                queue.append((node.left, index))
                queue.append((node.right, index))
        
        dp_rob, dp_not_rob = [0] * (index + 1), [0] * (index + 1)
        for i in range(index, -1, -1):
            if not graph[i]:
                dp_rob[i] = tree[i]
                dp_not_rob[i] = 0
            else:
                dp_rob[i] = tree[i] + sum(dp_not_rob[child] for child in graph[i])
                dp_not_rob[i] = sum(max(dp_rob[child], dp_not_rob[child]) for child in graph[i])
        return max(dp_rob[0], dp_not_rob[0])
        
        
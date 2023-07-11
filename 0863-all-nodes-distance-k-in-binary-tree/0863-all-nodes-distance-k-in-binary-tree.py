# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        graph = defaultdict(list)
        def build_graph(child: TreeNode, parent: TreeNode) -> None:
            if child and parent:
                graph[child.val].append(parent.val)
                graph[parent.val].append(child.val)
            if child.left:
                build_graph(child.left, child)
            if child.right:
                build_graph(child.right, child)
        build_graph(root, None)
        
        ans, visited = [], set([target.val])
        def dfs(curr: int, dist: int) -> None:
            if dist == k:
                ans.append(curr)
                return
            for neighbor in graph[curr]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    dfs(neighbor, dist + 1)
        dfs(target.val, 0)
        
        return ans
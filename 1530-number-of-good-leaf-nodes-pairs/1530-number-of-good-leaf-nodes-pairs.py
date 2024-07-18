# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _traverse_tree(self, curr: TreeNode, prev: TreeNode, graph: Dict[TreeNode, List[TreeNode]], leaves: Set[TreeNode]) -> None:
        if not curr:
            return
        
        if not (curr.left or curr.right):
            leaves.add(curr)
        
        if prev:
            if prev not in graph:
                graph[prev] = []
            graph[prev].append(curr)
            
            if curr not in graph:
                graph[curr] = []
            graph[curr].append(prev)
            
        self._traverse_tree(curr.left, curr, graph, leaves)
        self._traverse_tree(curr.right, curr, graph, leaves)
    
    def countPairs(self, root: TreeNode, distance: int) -> int:
        graph = dict()
        leaves = set()
        self._traverse_tree(root, None, graph, leaves)
        
        ans = 0
        
        for leaf in leaves:
            queue, seen = deque(), set()
            queue.append(leaf)
            seen.add(leaf)
            
            for _ in range(distance + 1):
                # Clear all nodes in the queue (distance i away from leaf node)
                # Add the nodes' neighbors (distance i + 1 away from leaf node)
                sz = len(queue)
                for __ in range(sz):
                    curr = queue.popleft()
                    if curr in leaves and curr != leaf:
                        ans += 1
                    
                    if curr in graph:
                        for neighbor in graph[curr]:
                            if neighbor not in seen:
                                seen.add(neighbor)
                                queue.append(neighbor)
                            
        return ans >> 1
            
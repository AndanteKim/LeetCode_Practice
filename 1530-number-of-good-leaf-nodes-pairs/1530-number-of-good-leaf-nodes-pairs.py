# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find_ancestor(self, node: TreeNode) -> Dict[TreeNode, TreeNode]:
        queue = deque([(node, None)])
        ancestors = dict()
        
        while queue:
            child, parent = queue.popleft()
            ancestors[child] = parent
            
            if child.left:
                queue.append((child.left, child))
                
            if child.right:
                queue.append((child.right, child))
            
        return ancestors
    
    def find_leaves(self, node: TreeNode) -> Set[TreeNode]:
        leaves, queue = set(), deque([node])
        
        while queue:
            curr = queue.popleft()
            
            if not (curr.left or curr.right):
                leaves.add(curr)
            
            if curr.left:
                queue.append(curr.left)
                
            if curr.right:
                queue.append(curr.right)
        
        return leaves
        
    def countPairs(self, root: TreeNode, distance: int) -> int:
        ancestors = self.find_ancestor(root)
        leaves, pairs, ans = self.find_leaves(root), defaultdict(set), 0
        for node in leaves:
            origin, start = node, distance
            
            while start > 0 and node:
                queue = deque([(node, start)])
                
                while queue:
                    curr, remain = queue.popleft()
                    
                    if origin != curr and curr in leaves and curr not in pairs[origin]:
                        pairs[origin].add(curr)
                        ans += 1
                        continue
                    
                    if remain == 0:
                        continue
                    
                    if curr.left:
                        queue.append((curr.left, remain - 1))
                    
                    if curr.right:
                        queue.append((curr.right, remain - 1))
                
                node = ancestors[node]
                start -= 1
        
        return ans >> 1
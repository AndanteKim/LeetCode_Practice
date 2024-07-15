# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bfs(self, root: Optional[TreeNode]) -> Dict[TreeNode, TreeNode]:
        queue, ancestors = deque([(root, None)]), dict()
        
        # Find the depth
        while queue:
            child, parent = queue.popleft()
            ancestors[child] = parent
            
            if child.left:
                queue.append((child.left, child))
            
            if child.right:
                queue.append((child.right, child))
        
        return ancestors

    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        ancestors = self.bfs(root)
        tree_p, tree_q = None, None
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            
            if node.val == p:
                tree_p = node
                
            if node.val == q:
                tree_q = node
            
            if node.left:
                queue.append(node.left)
            
            if node.right:
                queue.append(node.right)
            
        curr_p, curr_q, ans = tree_p, tree_q, 0
        dist = 0
        while curr_p and curr_p != curr_q:
            curr_p = ancestors[curr_p]
            dist += 1
        
        if curr_p:
            return dist
            
        dist, curr_p = 0, tree_p
        while curr_q and curr_p != curr_q:
            curr_q = ancestors[curr_q]
            dist += 1
        
        if curr_q:
            return dist
            
        curr_p, curr_q, p_dist, q_dist = tree_p, tree_q, 0, 0
        
        while curr_p != curr_q:
            if ancestors[curr_p] and ancestors[curr_p] != curr_q:
                curr_p = ancestors[curr_p]
                p_dist += 1
            elif ancestors[curr_p] == curr_q:
                p_dist += 1
                break
            
            if ancestors[curr_q] and ancestors[curr_q] != curr_p:
                curr_q = ancestors[curr_q]
                q_dist += 1
            elif ancestors[curr_q] == curr_p:
                q_dist += 1
                break
        
        return p_dist + q_dist
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find_LCA(self, root: TreeNode, p: int, q: int) -> TreeNode:
        if not root or root.val == p or root.val == q:
            return root
        
        left = self.find_LCA(root.left, p, q)
        right = self.find_LCA(root.right, p, q)
        
        if left and right:
            return root
        
        return left if left else right
    
    
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        lca = self.find_LCA(root, p, q)
        bfs = deque([lca])
        dist, depth = 0, 0
        found_p, found_q = False, False
        
        while bfs and not ( found_p and found_q):
            sz = len(bfs)
            for _ in range(sz):
                # Dequeue the node
                node = bfs.popleft()
                if node.val == p:
                    dist += depth
                    found_p = True
                    
                if node.val == q:
                    dist += depth
                    found_q = True
                    
                if node.left:
                    bfs.append(node.left) # Enqueue left child
                    
                if node.right:
                    bfs.append(node.right) # Enqueue right child
                    
            depth += 1
            
        return dist
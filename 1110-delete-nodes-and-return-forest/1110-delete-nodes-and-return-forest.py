# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find_ancestors(self, root: TreeNode) -> Dict[TreeNode, TreeNode]:
        if not root:
            return dict()
        
        ancestors = dict()
        queue = deque([(root, None, None)])
        while queue:
            child, parent, dirs = queue.popleft()
            
            ancestors[child] = (parent, dirs)
            
            if child.left:
                queue.append((child.left, child, "L"))
                
            if child.right:
                queue.append((child.right, child, "R"))
                
        return ancestors
    
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        candidates = set(to_delete)
        ans = [] if root.val in candidates else [root]
        ancestors, queue = self.find_ancestors(root), deque([root])
        
        while queue:
            node, is_cut = queue.popleft(), False
            
            if node.val in candidates:
                is_cut = True
                parent, direction = ancestors[node]

                if parent and direction == "L":
                    parent.left = None
                elif parent and direction == "R":
                    parent.right = None
                
                candidates.remove(node.val)
                
            if node.left:
                queue.append(node.left)
                
                if is_cut and node.left.val not in candidates:
                    ans.append(node.left)
                
            if node.right:
                queue.append(node.right)
                
                if is_cut and node.right.val not in candidates:
                    ans.append(node.right)
                    
        return ans
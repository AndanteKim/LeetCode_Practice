# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        # Sets to track unique childre n and parents
        children, parents = set(), set()
        
        # Dictionary to store parent to children relationships
        parent_to_children = defaultdict(list)
        
        for parent, child, is_left in descriptions:
            parents.add(parent)
            children.add(child)
            parent_to_children[parent].append((child, is_left))
            
        # Find the root node by checking which node is
        # in parents but not in children
        for parent in parents.copy():
            if parent in children:
                parents.remove(parent)
        
        root = TreeNode(next(iter(parents)))
        queue = deque([root])
        
        while queue:
            parent = queue.popleft()
            
            # Iterate over children of current parent
            for child_val, is_left in parent_to_children.get(parent.val, []):
                child = TreeNode(child_val)
                queue.append(child)
                if is_left:
                    parent.left = child
                else:
                    parent.right = child
                    
        return root
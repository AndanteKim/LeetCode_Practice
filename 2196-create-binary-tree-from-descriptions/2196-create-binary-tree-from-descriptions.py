# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        # Step 1: Organize data
        all_nodes, children = set(), set()
        parents_to_children = defaultdict(list)
        
        for parent, child, is_left in descriptions:
            # Store child information under parent node
            parents_to_children[parent].append((child, is_left))
            
            all_nodes.add(parent)
            all_nodes.add(child)
            children.add(child)
            
        # Step 2: Find the root
        root_val = (all_nodes - children).pop()
        
        # Step 3 & 4: Build the tree using DFS
        def dfs(val: int) -> TreeNode:
            # Create new TreeNode for current value
            node = TreeNode(val)
            
            # If current node has children, recursively build them
            if val in parents_to_children:
                for child, is_left in parents_to_children[val]:
                    # Attach child node based on is_left flag
                    if is_left:
                        node.left = dfs(child)
                    else:
                        node.right = dfs(child)
                        
            return node
        
        return dfs(root_val)
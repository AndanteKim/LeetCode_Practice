# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _backtrack_path(self, node: Optional[TreeNode], path_tracker: Dict[TreeNode, Tuple[TreeNode, str]]) -> str:
        path = []
        
        # Construct the path
        while node in path_tracker:
            # Add the directions in reverse order and move on to the previous node
            path.append(path_tracker[node][1])
            node = path_tracker[node][0]
        
        path.reverse()
        return "".join(path)
    
    def _populate_parent_map(self, node: Optional[TreeNode], parent_map: Dict[int, TreeNode]) -> None:
        if not node:
            return
        
        # Add children to the map and recurse further
        if node.left:
            parent_map[node.left.val] = node
            self._populate_parent_map(node.left, parent_map)
            
        if node.right:
            parent_map[node.right.val] = node
            self._populate_parent_map(node.right, parent_map)
            
    def _find_start_node(self, node: Optional[TreeNode], start_value: int) -> TreeNode:
        if not node:
            return None
        
        if node.val == start_value:
            return node
        
        left_result = self._find_start_node(node.left, start_value)
        
        # If left subtree returns a node, it must be start node. Return it
        # Otherwise, return whatever is returned by right subtree.
        if left_result:
            return left_result
        
        return self._find_start_node(node.right, start_value)
    
    
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        # Map to store the parent nodes
        parent_map = dict()
        
        # Find the start node and populate parent map
        start_node = self._find_start_node(root, startValue)
        self._populate_parent_map(root, parent_map)
        
        # Perform BFS to find the path
        q = deque([start_node])
        visited_nodes = set()
        # Key: next node, Value: <current node, direction>
        path_tracker = dict()
        visited_nodes.add(start_node)
        
        while q:
            curr_element = q.popleft()
            
            # If destination is reached, return the path
            if curr_element.val == destValue:
                return self._backtrack_path(curr_element, path_tracker)
            
            # Check and add parent node
            if curr_element.val in parent_map:
                parent_node = parent_map[curr_element.val]
                if parent_node not in visited_nodes:
                    q.append(parent_node)
                    path_tracker[parent_node] = (curr_element, "U")
                    visited_nodes.add(parent_node)
                    
            # Check and add left child
            if curr_element.left and curr_element.left not in visited_nodes:
                q.append(curr_element.left)
                path_tracker[curr_element.left] = (curr_element, "L")
                visited_nodes.add(curr_element.left)
                
            # Check and add right child
            if curr_element.right and curr_element.right not in visited_nodes:
                q.append(curr_element.right)
                path_tracker[curr_element.right] = (curr_element, "R")
                visited_nodes.add(curr_element.right)
                
        # This line should never be reached if the tree is valid
        return ""
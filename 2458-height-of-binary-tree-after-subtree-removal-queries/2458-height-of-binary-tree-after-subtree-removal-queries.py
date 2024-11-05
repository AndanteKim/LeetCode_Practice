# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _dfs(self, node: TreeNode, depth: int, node_index_map: Dict[int, int], node_depths: List[int]) -> None:
        if not node:
            return
        
        node_index_map[node.val] = len(node_depths)
        node_depths.append(depth)
        
        self._dfs(node.left, depth + 1, node_index_map, node_depths)
        self._dfs(node.right, depth + 1, node_index_map, node_depths)
        
    # Calculate the size of the subtree for each node
    def _calculate_subtree_size(self, node: TreeNode, subtree_size: Dict[int, int]) -> int:
        if not node:
            return 0
        
        left_size = self._calculate_subtree_size(node.left, subtree_size)
        right_size = self._calculate_subtree_size(node.right, subtree_size)
        
        total_size = left_size + right_size + 1
        subtree_size[node.val] = total_size
        
        return total_size
    
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        # Dictionaries to store the index of each node value and the number of nodes in the subtree for each node
        node_index_map, subtree_size = dict(), dict()
        
        # Lists to store node depths and maximum depths from left and right
        node_depths, max_depth_from_left, max_depth_from_right = [], [], []
        
        # Perform DFS to populate node_index_map and node_depths
        self._dfs(root, 0, node_index_map, node_depths)
        
        total_nodes = len(node_depths)
        # Calculate subtree sizes
        self._calculate_subtree_size(root, subtree_size)
        
        # Calculate maximum depths from left and right
        max_depth_from_left.append(node_depths[0])
        max_depth_from_right.append(node_depths[-1])
        
        for i in range(1, total_nodes):
            max_depth_from_left.append(max(max_depth_from_left[i - 1], node_depths[i]))
            max_depth_from_right.append(max(max_depth_from_right[i - 1], node_depths[total_nodes - i - 1]))
            
        max_depth_from_right.reverse()
        
        # Process queries
        ans = []
        
        for query_node in queries:
            start_index = node_index_map[query_node] - 1
            end_index = start_index + 1 + subtree_size[query_node]
            
            max_depth = max_depth_from_left[start_index]
            if end_index < total_nodes:
                max_depth = max(max_depth, max_depth_from_right[end_index])
            ans.append(max_depth)
            
        return ans
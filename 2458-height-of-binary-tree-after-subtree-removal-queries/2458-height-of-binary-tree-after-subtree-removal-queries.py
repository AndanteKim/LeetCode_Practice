# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Depth-first search to build the Euler tour and store node information
    def _dfs(self, node: TreeNode, height: int, euler_tour: List[int], node_heights: Dict[int, int], first_occurrence: Dict[int, int], last_occurrence: Dict[int, int]) -> None:
        if not node:
            return
        
        node_heights[node.val] = height
        first_occurrence[node.val] = len(euler_tour)
        euler_tour.append(node.val)
        
        self._dfs(node.left, height + 1, euler_tour, node_heights, first_occurrence, last_occurrence)
        self._dfs(node.right, height + 1, euler_tour, node_heights, first_occurrence, last_occurrence)
        
        last_occurrence[node.val] = len(euler_tour)
        euler_tour.append(node.val)
        
    
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        # Lists and dictionaries to store tree information
        euler_tour = []
        node_heights, first_occurrence, last_occurrence = dict(), dict(), dict()
        
        # Perform DFS to build Euler tour and node information
        self._dfs(root, 0, euler_tour, node_heights, first_occurrence, last_occurrence)
        tour_size = len(euler_tour)
        max_depth_left, max_depth_right = [0] * tour_size, [0] * tour_size
        
        # Initialize the first and last elements of max_height arrays
        max_depth_left[0] = max_depth_right[-1] = node_heights[root.val]
        
        # Build max_depth_left and max_depth_right arrays
        for i in range(1, tour_size):
            max_depth_left[i] = max(max_depth_left[i - 1], node_heights[euler_tour[i]])
            
        for i in range(tour_size - 2, -1, -1):
            max_depth_right[i] = max(max_depth_right[i + 1], node_heights[euler_tour[i]])
            
        query_size = len(queries)
        ans = [0] * query_size
        
        # Process queries
        for i in range(query_size):
            q = queries[i]
            left_max = max_depth_left[first_occurrence[q] - 1] if first_occurrence[q] > 0 else 0
            right_max = max_depth_right[last_occurrence[q] + 1] if last_occurrence[q] < tour_size - 1 else 0
            ans[i] = max(left_max, right_max)
        
        return ans
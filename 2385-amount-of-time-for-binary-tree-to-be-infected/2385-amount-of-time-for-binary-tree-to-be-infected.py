# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convert(self, current: TreeNode, parent: int, tree_map: Dict[int, Set[int]]) -> None:
        if not current:
            return
        
        if current.val not in tree_map:
            tree_map[current.val] = set()
        
        adj_list = tree_map[current.val]
        if parent != 0:
            adj_list.add(parent)
        
        if current.left:
            adj_list.add(current.left.val)
        
        if current.right:
            adj_list.add(current.right.val)
        
        self.convert(current.left, current.val, tree_map)
        self.convert(current.right, current.val, tree_map)
    
    
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        tree_map: Dict[int, Set[int]] = {}
        self.convert(root, 0, tree_map)
        queue, ans = deque([start]), 0
        visited = {start}
        
        while queue:
            level = len(queue)
            while level > 0:
                current = queue.popleft()
                for num in tree_map[current]:
                    if num not in visited:
                        visited.add(num)
                        queue.append(num)
                level -= 1
            ans += 1
        return ans - 1
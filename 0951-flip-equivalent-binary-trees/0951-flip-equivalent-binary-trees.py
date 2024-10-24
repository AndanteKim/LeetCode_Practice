# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def bfs(root: Optional[TreeNode], match: DefaultDict[int, Set[int]]) -> None:
            if not root:
                return
            
            queue = deque([root])
            
            while queue:
                node = queue.popleft()
                match[node.val] = set()
                if node.left:
                    match[node.val].add(node.left.val)
                    queue.append(node.left)
                if node.right:
                    match[node.val].add(node.right.val)
                    queue.append(node.right)
        
        match1, match2 = defaultdict(set), defaultdict(set)
        bfs(root1, match1)
        bfs(root2, match2)
        
        
        return match1 == match2
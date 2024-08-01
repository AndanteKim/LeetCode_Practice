# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.pq = []
        stack = [root]
        while stack:
            node = stack.pop()
            heappush(self.pq, node.val)
            
            if node.left:
                stack.append(node.left)
                
            if node.right:
                stack.append(node.right)

    def next(self) -> int:
        return heappop(self.pq) if self.hasNext else -1

    def hasNext(self) -> bool:
        return len(self.pq) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        def helper(min_limit: int, max_limit: int) -> bool:
            nonlocal i
            if i == len(preorder):
                return True
            
            root = preorder[i]
            if root < min_limit or root > max_limit:
                return False
            i += 1
            
            left = helper(min_limit, root)
            right = helper(root, max_limit)
            return left or right
        
        i = 0
        return helper(float('-inf'), float('inf'))
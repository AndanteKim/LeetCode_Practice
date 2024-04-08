class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        
        def helper(i: List[int], min_limit: int, max_limit: int) -> bool:
            if i[0] == len(preorder):
                return True
            
            root = preorder[i[0]]
            if not (min_limit < root < max_limit):
                return False
            
            i[0] += 1
            left = helper(i, min_limit, root)
            right = helper(i, root, max_limit)
            
            return left or right
        
        i = [0]
        return helper(i, float('-inf'), float('inf'))
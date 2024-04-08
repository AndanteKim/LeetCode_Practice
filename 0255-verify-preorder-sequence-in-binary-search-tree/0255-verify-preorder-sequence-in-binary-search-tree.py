class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        min_limit, i = float('-inf'), 0
        
        for num in preorder:
            while i > 0 and preorder[i - 1] < num:
                min_limit = preorder[i - 1]
                i -= 1
                
            if min_limit >= num:
                return False
            preorder[i] = num
            i += 1
        
        return True
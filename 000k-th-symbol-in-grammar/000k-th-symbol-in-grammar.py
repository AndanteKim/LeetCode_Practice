class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        def recursion(remain: int, pos: int) -> int:
            # Base case: First row will only have one symbol '0'
            if remain == 1:
                return 0
            
            total_nodes = 2 ** (remain - 1)
            half_nodes = (total_nodes) >> 1
            
            # If the target is present in the right half, we switch to the respective left half symbol
            if pos > half_nodes:
                return 1 - recursion(remain, pos - half_nodes)
            
            # Otherwise, we switch to the previous row
            return recursion(remain - 1, pos)
        
        return recursion(n, k)
class Solution:
    def recursion(self, n: int, k: int) -> int:
        # First row will only have one symbol '0'
        if n == 1:
            return 0
        
        total_elements = 1 << (n - 1)
        half_elements = total_elements // 2
        
        # If the target is present in the right half, we switch to the respective left half symbol
        if k > half_elements:
            return 1 - self.recursion(n, k - half_elements)
        # Otherwise, we switch to the previous row
        return self.recursion(n - 1, k)
    
    def kthGrammar(self, n: int, k: int) -> int:
        return self.recursion(n, k)
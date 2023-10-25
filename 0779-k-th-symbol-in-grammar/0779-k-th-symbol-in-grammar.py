class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        
        # We assume the symbol at the target position is '1'
        symbol = 1
        
        for curr_row in range(n, 1, -1):
            total_elements = 1 << (curr_row - 1)
            half_elements = total_elements // 2
            
            # If 'k' lies in the right half symbol, then we flip over to the respective left half symbol
            if k > half_elements:
                # Flip the symbol
                symbol = 1 - symbol
                # Change the position after flipping
                k -= half_elements
                
        # We reached the 1st row; if the symbol is not '0', we started with the wrong symbol
        if symbol != 0:
            # Thus, the start symbol was '0', not '1'.
            return 0
            
        # The start symbol was indeed what we started with, a '1'.
        return 1
        
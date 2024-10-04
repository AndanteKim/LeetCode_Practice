class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        # Base case
        if n == 1:
            return 0
        
        symbol = 1
        
        for curr_row in range(n, 1, -1):
            total_nodes = 1 << (curr_row - 1)
            half_nodes = total_nodes >> 1
            
            # If 'k' lies in the right half symbol 
            if k > half_nodes:
                # Flip the symbol
                symbol ^= 1
                                
                # Change the position after flipping
                k -= half_nodes
        
        # We reached the 1st row; If the symbol isn't '0', we started with the wrong symbol.
        if symbol != 0:
            # Thus, the start symbol was '0', not '1'.
            return 0
        
        # The start symbol was indeed what we started with a '1'.
        return 1
class Solution:
    def minEnd(self, n: int, x: int) -> int:
        ans = 0
        # Reducing n by 1 to exclude x from the iteration
        n -= 1
        
        # Step 1: Initialize lists to hold the binary representation of x and n - 1
        bin_x, bin_n = [0] * 64, [0] * 64
        
        # Step 2: Build binary representations of x and n - 1
        for i in range(64):
            bit = (x >> i) & 1  # Extract i-th bit of x
            bin_x[i] = bit
            
            bit = (n >> i) & 1  # Extract i-th bit of n - 1
            bin_n[i]= bit
            
        pos_x, pos_n = 0, 0
        
        # Step 3: Combine binary representation of x and n - 1
        while pos_x < 63:
            # Traverse binary_x until we find a 0 bit
            while bin_x[pos_x] != 0 and pos_x < 63:
                pos_x += 1
                
            # Copy bits from bin_n (n - 1) into bin_x (x) starting from the first 0
            bin_x[pos_x] = bin_n[pos_n]
            pos_x += 1
            pos_n += 1
            
        # Step 4: Rebuild the final result from the combined binary representation
        for i in range(64):
            if bin_x[i] == 1:
                # Convert binary bit to decimal value
                ans += (1 << i)
                
        return ans
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # Dp array to store ugly numbers
        ugly_nums = [0] * n
        
        # The first ugly number is 1
        ugly_nums[0] = 1
        
        # 3 pointers for the multiples of 2, 3, and 5
        idx_2, idx_3, idx_5 = 0, 0, 0
        next_2, next_3, next_5 = 2, 3, 5
        
        # Generate ugly numbers until we reach the nth one
        for i in range(1, n):
            # Find the next ugly number as the minimum of the next multiples
            next_ugly = min(next_2, next_3, next_5)
            ugly_nums[i] = next_ugly
            
            # Update the corresponding pointer and next multiple
            if next_ugly == next_2:
                idx_2 += 1
                next_2 = ugly_nums[idx_2] * 2
            
            if next_ugly == next_3:
                idx_3 += 1
                next_3 = ugly_nums[idx_3] * 3
                
            if next_ugly == next_5:
                idx_5 += 1
                next_5 = ugly_nums[idx_5] * 5
                
        # Return the nth ugly number
        return ugly_nums[n - 1]
                
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # Set to store potential ugly numbers
        ugly_sets = set()
        
        # Start with 1, the first ugly number
        ugly_sets.add(1)
        
        for i in range(n):
            # Get the smallest number from the set
            curr_ugly = min(ugly_sets)
            
            # Remove it from the set
            ugly_sets.remove(curr_ugly)
            
            # Insert the next potential ugly numbers
            ugly_sets.add(curr_ugly * 2)
            ugly_sets.add(curr_ugly * 3)
            ugly_sets.add(curr_ugly * 5)
            
        return curr_ugly
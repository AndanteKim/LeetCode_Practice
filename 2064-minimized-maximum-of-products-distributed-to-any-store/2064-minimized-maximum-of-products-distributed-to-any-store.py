class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def is_possible(x: int) -> bool:
            # Pointer to the first not fully distributed product type
            # Remaining quantity of the jth product type
            remaining, j = quantities[0], 0
            
            # Loop through each store
            for _ in range(n):
                # Check if the remaining quantity of the jth product type
                # can be fully distributed to the ith store
                if remaining <= x:
                    # If yes, move the pointer to the next product type
                    j += 1
                    
                    # Check if all products have been distributes
                    if j == m:
                        return True
                    else:
                        remaining = quantities[j]
                else:
                    # Distribute the maximum possible quantity (x) to the ith store
                    remaining -= x
                    
            return False
                        
        # Initialize the boundaries of the binary search
        left, right, m = 0, max(quantities), len(quantities)
        
        # Perform binary search until the boundaries converge
        while left < right:
            mid = (left + right) >> 1
            
            if is_possible(mid):
                # Try for a smaller maximum
                right = mid
            else:
                # Increase the minimum possible maximum
                left = mid + 1
                
        return left
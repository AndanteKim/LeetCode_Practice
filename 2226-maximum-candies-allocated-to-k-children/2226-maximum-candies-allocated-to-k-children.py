class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        def _is_possible(size: int) -> bool:
            # Initialize the total number of children that can be served
            piles = 0

            # Iterate over all piles to calculate how many children each pile can serve
            for candy in candies:
                piles += candy // size
            
            return piles >= k
        
        # Set the initial search range for binary search
        left, right = 0, max(candies)

        # Binary search to find the maximum number of candies each child can get
        while left < right:
            # Calculate the middle value of the current range
            mid = (left + right + 1) >> 1
            
            # Check if it's possible to allocate candies, so that each child gets 'middle' candies
            if _is_possible(mid):
                # If possible, move to the upper half to search for a larger number
                left = mid
            else:
                # Otherwise, move to the lower half
                right = mid - 1
        
        return left
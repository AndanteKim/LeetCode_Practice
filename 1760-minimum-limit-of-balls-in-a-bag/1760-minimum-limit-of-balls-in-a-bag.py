class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        # Helper function to check if a distribution is possible for a given max_balls_in_bag
        def is_possible(max_balls_in_bag: int) -> bool:
            total_ops = 0
            
            # Iterate through each bag in the array
            for num in nums:
                # Calculate the number of operations needed to split this bag
                total_ops += ceil(num / max_balls_in_bag) - 1
                
                # If total operations exceed max_opertaions, return False
                if total_ops > maxOperations:
                    return False
            
            # We can split the balls within the allowed operations, return True
            return True 
        
        # Binary search bounds
        left, right = 1, max(nums)
        
        # Perform binary search to find the optimal max_balls_in_bag
        while left < right:
            mid = (left + right) >> 1
            
            # Check if a valid distribution is possible with the current middle value
            if is_possible(mid):
                # If possible, try a smaller value (shift right to middle)
                right = mid
            else:
                # If not possible, tru a larger value (shift left to middle + 1)
                left = mid + 1
                
        # Return the smallest possible value for max_balls_in_bag
        return left
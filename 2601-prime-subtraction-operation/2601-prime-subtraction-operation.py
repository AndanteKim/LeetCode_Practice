class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        max_elem, n = max(nums), len(nums)
        
        # Store the sieve array
        sieve = [1] * (max_elem + 1)
        sieve[1] = 0
        
        for i in range(2, int(sqrt(max_elem + 1)) + 1):
            if sieve[i] == 1:
                for j in range(i * i, max_elem + 1, i):
                    sieve[j] = 0
                    
        # Start by storing the currValue as 1, and the initial index as 0.
        i, curr_val = 0, 1
        
        while i < n:
            # Store the difference needed to make nums[i] equal to curr_val
            diff = nums[i] - curr_val
            
            # If difference is less than 0, then nums[i] is already less than
            # curr_val. Return False in this case.
            if diff < 0:
                return False
            
            # If the difference is prime or zero, then nums[i] can be made equal to curr_val
            if sieve[diff] or diff == 0:
                i += 1
                curr_val += 1
            else:
                # Otherwise, try for the next curr_val
                curr_val += 1
                
        return True
class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        max_elem, n = max(nums), len(nums)
        
        # Store the previous prime array.
        prev_prime = [0] * (max_elem + 1)
        
        for i in range(2, max_elem + 1):
            if self.check_prime(i):
                prev_prime[i] = i
            else:
                prev_prime[i] = prev_prime[i - 1]
                
        for i in range(n):
            # In case of first index, we need to find the largest prime less than nums[0]
            if i == 0:
                bound = nums[0]
            else:
                # Otherwise, we need to find the largest prime, that makes the
                # current element closest to the previous element.
                bound = nums[i] - nums[i - 1]
            
            # If the bound is less than or equal to 0, then the array cannot be
            # made strictly increasing.
            if bound <= 0:
                return False
            
            # Find the largest prime less than bound.
            largest_prime = prev_prime[bound - 1]
            
            # Subtract this value from nums[i].
            nums[i] -= largest_prime
            
        return True
    
    def check_prime(self, x: int) -> bool:
        for i in range(2, int(x ** 0.5) + 1):
            if x % i == 0:
                return False
        return True
                
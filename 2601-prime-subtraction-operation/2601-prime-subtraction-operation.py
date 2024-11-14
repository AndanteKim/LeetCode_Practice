class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        # Create sieves cache
        prime = [True for i in range(1001)]
        i = 2
        while i * i <= 1000:
            for p in range(i * i, 1001, i):
                prime[p] = False
            i += 1
            
        prime = [p for p in range(2, 1001) if prime[p]]
        
        n, p = len(nums), len(prime)
        
        for i in range(n - 2, -1, -1):
            if nums[i] >= nums[i + 1]:
                left = bisect_right(prime, nums[i] - nums[i + 1])
                
                if left == p:
                    return False
                nums[i] -= prime[left]
                
                # 0 means prime == target or prime > target
                if nums[i] <= 0:
                    return False
                
        return True
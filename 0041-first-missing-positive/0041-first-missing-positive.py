class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n, contains1 = len(nums), False
        
        # Replace negative numbers, zeros,
        # and numbers larger than n with 1s.
        # After this nums contains only positive numbers.
        for i in range(n):
            # Check whether 1 is in the original array
            if nums[i] == 1:
                contains1 = True
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1
                
        if not contains1:
            return 1
        
        # Mark whether integer 1 to n are in nums
        # Use index as a hash key and negative sign as a presence detector.
        for i in range(n):
            value = abs(nums[i])
            # If you meet number a in the array, - change the sign of a-th element
            # Be careful with duplicates : do it only once.
            if value == n:
                nums[0] = -abs(nums[0])
            else:
                nums[value] = -abs(nums[value])
        
        # First positive in nums is the smallest missing positive integer
        for i in range(1, n):
            if nums[i] > 0:
                return i
        
        # nums[0] stores whether n is in nums
        if nums[0] > 0:
            return n
        
        # If nums contains all elements 1 to n
        # the smallest missing positive number is n + 1
        return n + 1
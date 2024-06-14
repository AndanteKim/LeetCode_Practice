class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        n, max_val, min_incre = len(nums), max(nums), 0
        
        # Create a freq_count array to store the frequency of each value in nums
        freq_count = [0] * (n + max_val + 1)
        
        # Populate freq_count array with the frequency of each value in nums
        for val in nums:
            freq_count[val] += 1
        
        # Iterate over the freq_count array to make all values unique
        for i in range(len(freq_count)):
            if freq_count[i] <= 1:
                continue
            
            # Determine excess occurrences, carry them over to the next value,
            # ensure single occurrence for current value, and update min_increments
            duplicates = freq_count[i] - 1
            freq_count[i + 1] += duplicates
            freq_count[i] = 1
            min_incre += duplicates
        
        return min_incre
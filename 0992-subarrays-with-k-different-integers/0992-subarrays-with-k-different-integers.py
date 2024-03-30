class Solution:
    # Helper function to count the number of subarrays with at most k distinct elements
    def slidingWindowAtMost(self, nums: List[int], distinctK: int) -> int:
        # To store the occurrences of each element
        freq = defaultdict(int)
        left, total_count = 0, 0
        
        # Right pointer of the sliding window iterates through the array.
        for right in range(len(nums)):
            freq[nums[right]] += 1
            
            # If the number of distinct elements in the window exceeds k,
            # we shrink the window from the left until we have at most k distinct elements.
            while len(freq) > distinctK:
                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                left += 1
            
            # Update the total count by adding the length of the current subarray.
            total_count += right - left + 1
        
        return total_count
    
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.slidingWindowAtMost(nums, k) - self.slidingWindowAtMost(nums, k - 1)
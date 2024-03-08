class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freqs, max_freq, total_freq = dict(), 0, 0
        
        # Find the frequency of each element
        # Determine the maximum frequency
        # Calculate the total frequencies of elements with the maximum frequency
        for num in nums:
            freqs[num] = freqs.get(num, 0) + 1
            freq = freqs[num]
            
            # If we discover a higher frequency element
            # Update max_frequency
            # Re-set total_freqs to the new max_freq
            if freq > max_freq:
                max_freq = freq
                total_freq = freq
            # If we find an element with the max frequency, add it to the total
            elif freq == max_freq:
                total_freq += freq
            
        return total_freq
            
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        prefix_max, suffix_min = arr[:], arr[:]
        
        # Fill the prefix_max array
        for i in range(1, n - 1):
            prefix_max[i] = max(prefix_max[i], prefix_max[i - 1])
            
        # Fill the suffix_min array in reverse order
        for i in range(n - 2, -1, -1):
            suffix_min[i] = min(suffix_min[i], suffix_min[i + 1])
        
        chunks = 0
        for i in range(n):
            # A new chunk can be created
            if i == 0 or suffix_min[i] > prefix_max[i - 1]:
                chunks += 1
                
        return chunks
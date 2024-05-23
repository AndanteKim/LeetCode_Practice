class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        # Frequency map to track elements
        freq_map = defaultdict(int)
        # Sort nums array
        nums.sort()
        self.n = len(nums)
        return self._count_beautiful_subsets(nums, k, freq_map, 0) - 1
    
    def _count_beautiful_subsets(self, nums: List[int], diff: int, freq_map: DefaultDict[int, int], i: int) -> int:
        # Base case: Return 1 for a subset of size 1
        if i == self.n:
            return 1
        
        # Count subsets where nums[i] is not taken
        total_count = self._count_beautiful_subsets(nums, diff, freq_map, i + 1)
        
        # If nums[i] can be taken without violating the condition
        if nums[i] - diff not in freq_map:
            freq_map[nums[i]] += 1 # Mark nums[i] as taken
            
            # Recursively count subsetse where nums[i] is taken
            total_count += self._count_beautiful_subsets(nums, diff, freq_map, i + 1)
            
            freq_map[nums[i]] -= 1 # Backtrack: mark nums[i] as not taken
            
            # Remove nums[i] from freq_map if its count becomes 0
            if freq_map[nums[i]] == 0:
                del freq_map[nums[i]]
        
        return total_count
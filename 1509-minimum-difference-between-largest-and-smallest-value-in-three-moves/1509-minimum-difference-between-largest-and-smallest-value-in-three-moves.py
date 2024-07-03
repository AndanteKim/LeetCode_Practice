class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 4:
            return 0
        
        # Find the 4 smallest elements
        smallest_four = sorted(heapq.nsmallest(4, nums))
        
        # Find the 4 largest elements
        largest_four = sorted(heapq.nlargest(4, nums))
        
        min_diff = float('inf')
        
        # Four scenarios to compute the minimum difference
        for i in range(4):
            min_diff = min(min_diff, largest_four[i]- smallest_four[i])
            
        return min_diff
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Heap sort
        # Edge case: If all numbers are zero, return "0"
        if not any(nums):
            return "0"
        
        # Custom comparison fuction for heapq (simulating the comparator)
        class larger_str_comparator(str):
            def __lt__(self, other: str):
                # Custon comparison: return True if self + other > other + self
                return self + other > other + self
            
        # Priority queue (min-heap), but we push elements using a custom comparator
        heap = []
        
        for num in nums:
            heappush(heap, larger_str_comparator(str(num)))
            
        # Build the result string by popping from the heap
        ans = []
        while heap:
            ans.append(heappop(heap))
            
        # Concatenate and return the result
        largest = "".join(ans)
        
        # Handle case where all elements are "0"
        return "0" if largest[0] == "0" else largest
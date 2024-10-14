class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        # Define a max-heap by using a min-heap with negative values
        pq = []
        for num in nums:
            heappush(pq, -num)
        
        ans = 0
        while pq and k > 0:
            # Retrieve the max element (invert the sign because it's stored as negative.)
            num = -heappop(pq)
            ans += num
            
            # Add one-third of the max element back to the heap. Rounded up using integer division.
            num = num // 3 + 1 if (num // 3) != num / 3 else num // 3
            k -= 1
            if num > 0:
                heappush(pq, -num)
                
        return ans
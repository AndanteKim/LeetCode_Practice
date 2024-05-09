class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        # Convert the list into a max heap ny inverting the happiness values
        # Pythion's default heap data structure is a min heap
        max_heap = [-h for h in happiness]
        heapq.heapify(max_heap)
        
        ans, turns = 0, 0
        
        for i in range(k):
            # Invert again to get the original value
            ans += max(-heapq.heappop(max_heap) - turns, 0)
            
            # Increment turns for the next iteration
            turns += 1
        
        return ans
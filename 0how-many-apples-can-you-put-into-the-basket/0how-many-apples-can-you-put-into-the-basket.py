class Solution:
    def maxNumberOfApples(self, weight: List[int]) -> int:
        heapify(weight)
        ans = units = 0
        
        while weight and units + weight[0] <= 5000:
            units += heappop(weight)
            ans += 1
        return ans
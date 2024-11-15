class Solution:
    def shareCandies(self, candies: List[int], k: int) -> int:
        ans, d = 0, Counter(candies)
        
        for i, c in enumerate(candies):
            d[c] -= 1
            if d[c] == 0:
                del d[c]
            
            if i >= k:
                d[candies[i - k]] += 1
            
            if i >= k - 1:
                ans = max(ans, len(d))
                
        return ans
class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        
        pair_weights = [0] * (n - 1)
        for i in range(n - 1):
            pair_weights[i] = weights[i] + weights[i + 1]
        pair_weights.sort()
        
        ans = 0
        for i in range(k - 1):
            ans += pair_weights[n - 2 - i] - pair_weights[i]
            
        return ans
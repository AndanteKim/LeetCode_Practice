class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        # We collect and sort the value of all n - 1 pairs
        n = len(weights)
        pair_weights = [weights[i] + weights[i + 1] for i in range(n - 1)]

        # Since python's sort function sorts the whole list, we don't limit to the first n -1 elements here
        pair_weights.sort()
        
        # Get the difference between the largest k - 1 values and the smallest k - 1 values
        ans = 0
        for i in range(k - 1):
            ans += pair_weights[n - 2 - i] - pair_weights[i]

        return ans
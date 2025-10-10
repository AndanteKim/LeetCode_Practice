class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i >= n:
                return 0
            
            return energy[i] + dp(i + k)

        n = len(energy)
        return max(dp(i) for i in range(n)) 
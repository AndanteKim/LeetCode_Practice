class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        #@lru_cache(maxsize = None)
        def dp(i: int, memo: List[int]) -> int:
            if i >= n:
                return 0
            
            if memo[i] != -1:
                return memo[i]

            memo[i] = energy[i] + dp(i + k, memo)
            return memo[i]

        n = len(energy)
        memo = [-1] * n
        return max(dp(i, memo) for i in range(n)) 
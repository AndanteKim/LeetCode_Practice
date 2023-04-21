class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        @lru_cache(None)
        def backtrack(i: int, currProfit: int, people: int) -> None:
            if i >= len(group):
                return currProfit >= minProfit
            ways = 0
            if people + group[i] <= n:
                ways += backtrack(i + 1, min(minProfit, currProfit + profit[i]), people + group[i])
            ways += backtrack(i + 1, currProfit, people)
            
            return ways
        
        return backtrack(0, 0, 0) % (10 ** 9 + 7)
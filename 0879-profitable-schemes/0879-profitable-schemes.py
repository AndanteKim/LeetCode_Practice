class Solution:
    def find(self, pos: int, count: int, profit: int, n: int, minProfit: int, group: List[int], profits: List[int]) -> int:
        if pos == len(group):
            return profit >= minProfit
        
        if self.memo[pos][count][profit] != -1:
            return self.memo[pos][count][profit]
        
        totalWays = self.find(pos + 1, count, profit, n, minProfit, group, profits)
        if count + group[pos] <= n:
            totalWays += self.find(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits)
        self.memo[pos][count][profit] = totalWays % self.mod
        return self.memo[pos][count][profit]
    
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        self.mod = int(1e9 + 7)
        self.memo = [[[-1] * 101 for _ in range(101)] for __ in range(101)]
        
        return self.find(0, 0, 0, n, minProfit, group, profit)
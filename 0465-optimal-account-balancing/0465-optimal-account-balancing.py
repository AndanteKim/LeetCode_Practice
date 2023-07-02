class Solution:
    def dfs(self, curr: int, balance_map: List[int]) -> int:
        while curr < self.n and not balance_map[curr]:
            curr += 1
        if curr == self.n:
            return 0
        cost = float('inf')
        for nxt in range(curr + 1, self.n):
            if balance_map[nxt] * balance_map[curr] < 0:
                balance_map[nxt] += balance_map[curr]
                cost = min(cost, 1 + self.dfs(curr + 1, balance_map))
                balance_map[nxt] -= balance_map[curr]
        return cost
    
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balance_map, self.n = [0] * 12, 12
        for start, end, amount in transactions:
            balance_map[start] += amount
            balance_map[end] -= amount
        
        
        return self.dfs(0, balance_map)
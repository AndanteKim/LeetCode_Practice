class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # BFS
        queue = deque([(amount, 0)])
        seen = set([amount])
        
        while queue:
            remain, curr_coins = queue.popleft()
            if remain == 0:
                return curr_coins
            
            for coin in coins:
                if remain - coin >= 0 and remain - coin not in seen:
                    queue.append((remain - coin, curr_coins + 1))
                    seen.add(remain - coin)
        
        return -1
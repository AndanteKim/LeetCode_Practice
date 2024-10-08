class Solution:
    def maximumCoins(self, heroes: List[int], monsters: List[int], coins: List[int]) -> List[int]:
        m, n = len(coins), len(heroes)
        pairs = []
        
        for i in range(m):
            pairs.append((monsters[i], coins[i]))
            
        ans = [0] * n
        pairs.sort()
        monsters.sort()
        prefix_coins = [0] * (m + 1)
        
        for i in range(m):
            prefix_coins[i + 1] += prefix_coins[i] + pairs[i][1]
        
        inf = 10 ** 10
        for i in range(n):
            hero = heroes[i]
            
            limit = bisect_left(pairs, (hero, inf))
            ans[i] = prefix_coins[limit]
                    
        return ans
class Solution:
    def maximumCoins(self, heroes: List[int], monsters: List[int], coins: List[int]) -> List[int]:
        m, n = len(coins), len(heroes)
        monsters_and_coins = []
        
        for i in range(m):
            monsters_and_coins.append((monsters[i], coins[i]))
            
        ans = [0] * n
        # Sort by ascending value of monster power
        monsters_and_coins.sort()
        prefix_coins = [0] * (m + 1)
        
        for i in range(m):
            prefix_coins[i + 1] += prefix_coins[i] + monsters_and_coins[i][1]
        
        inf = 10 ** 10
        for i in range(n):
            hero = heroes[i]
            
            limit = bisect_left(monsters_and_coins, (hero, inf))
            ans[i] = prefix_coins[limit]
                    
        return ans
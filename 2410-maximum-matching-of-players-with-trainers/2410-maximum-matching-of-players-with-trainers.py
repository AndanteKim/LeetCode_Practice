class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        
        p_i, t_i, ans = 0, 0, 0
        
        while p_i < len(players) and t_i < len(trainers):
            if players[p_i] <= trainers[t_i]:
                p_i += 1
                t_i += 1
                ans += 1
            else:
                t_i += 1
        return ans
            
            
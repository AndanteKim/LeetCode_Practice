class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losses_cnts = dict()
        
        for winner, loser in matches:
            losses_cnts[winner] = losses_cnts.get(winner, 0)
            losses_cnts[loser] = losses_cnts.get(loser, 0) + 1
            
        zero_lose, one_lose = [], []
        for player, count in losses_cnts.items():
            if count == 0:
                zero_lose.append(player)
            elif count == 1:
                one_lose.append(player)
        
        return [sorted(zero_lose), sorted(one_lose)]
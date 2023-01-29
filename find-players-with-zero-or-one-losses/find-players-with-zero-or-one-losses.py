class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        lost_lookup = OrderedDict()
        answer = [[], []]
        for winner, loser in matches:
            lost_lookup[loser] = 0
            lost_lookup[winner] = 0
        
        for winner, loser in matches:
            lost_lookup[loser] += 1
            
        for player in sorted(lost_lookup):
            if lost_lookup[player] == 0:
                answer[0].append(player)
            elif lost_lookup[player] == 1:
                answer[1].append(player)
        
        return answer
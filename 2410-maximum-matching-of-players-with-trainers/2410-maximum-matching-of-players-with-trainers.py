class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        pq = []
        for trainer in trainers:
            heappush(pq, trainer)

        ans = 0
        for player in players:
            while pq:
                capacity = heappop(pq)
                if capacity >= player:
                    ans += 1
                    break
        
        return ans
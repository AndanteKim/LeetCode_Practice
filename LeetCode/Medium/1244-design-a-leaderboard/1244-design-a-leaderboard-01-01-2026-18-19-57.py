class Leaderboard:

    def __init__(self):
        self.scores = dict()

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.scores:
            self.scores[playerId] = 0
        self.scores[playerId] += score

    def top(self, K: int) -> int:
        pq = []

        for x in self.scores.values():
            heappush(pq, x)
            if len(pq) > K:
                heappop(pq)
        
        ans = 0

        while pq:
            ans += heappop(pq)
        return ans

    def reset(self, playerId: int) -> None:
        self.scores[playerId] = 0


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
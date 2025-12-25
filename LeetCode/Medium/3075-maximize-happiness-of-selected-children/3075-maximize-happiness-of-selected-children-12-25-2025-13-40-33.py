class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        ans, not_happy, pq = 0, 0, [-h for h in happiness]
        heapify(pq)

        for _ in range(k):
            h = -heappop(pq)
            ans += max(0, h - not_happy)
            not_happy += 1

        return ans
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        pq = []
        for i in range(candidates):
            pq.append((costs[i], 0))
        
        for i in range(max(candidates, len(costs) - candidates), len(costs)):
            pq.append((costs[i], 1))
        
        heapify(pq)
        ans = 0
        next_head, next_tail = candidates, len(costs) - 1 - candidates
        
        for _ in range(k):
            cur_cost, cur_section_id = heappop(pq)
            ans += cur_cost
            if next_head <= next_tail:
                if cur_section_id == 0:
                    heappush(pq, (costs[next_head], 0))
                    next_head += 1
                else:
                    heappush(pq, (costs[next_tail], 1))
                    next_tail -= 1
        
        return ans
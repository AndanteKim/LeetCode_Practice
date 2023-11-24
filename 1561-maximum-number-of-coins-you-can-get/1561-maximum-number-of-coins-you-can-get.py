class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        
        ans, queue, triplets = 0, deque(piles), []
        while queue:
            Alice = queue.pop()
            I = queue.pop()
            Bob = queue.popleft()
            triplets.append((Alice, I, Bob))
            
        for triplet in triplets:
            ans += triplet[1]
        
        return ans
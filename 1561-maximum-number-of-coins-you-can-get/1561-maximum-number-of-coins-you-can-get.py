class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        queue, ans = deque(piles), 0
        
        while queue:
            # Alice
            queue.pop()
            # I
            ans += queue.pop()
            # Bob
            queue.popleft()
            
        return ans
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        N, queue = len(deck), deque()
        
        # Create aa queue of indices
        for i in range(N):
            queue.append(i)
            
        deck.sort()
        
        # Put cards at correct index in ans
        ans = [0] * N
        for card in deck:
            ans[queue.popleft()] = card
            
            # Move next card to bottom
            if queue:
                queue.append(queue.popleft())
        
        return ans
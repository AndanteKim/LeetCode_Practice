class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        queue, time = deque(), 0
        
        for i in range(len(tickets)):
            if i == k:
                queue.append((tickets[i], True))
            else:
                queue.append((tickets[i], False))
                
        while queue:
            left, target_turn = queue.popleft()
            
            # buy a ticket for each turn of people
            left -= 1
            time += 1
            
            if left > 0:
                queue.append((left, target_turn))
            elif target_turn:
                return time
            
        return -1
            
        
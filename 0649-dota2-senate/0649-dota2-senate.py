class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        
        r_queue, d_queue = deque(), deque()
        for i in range(n):
            if senate[i] == 'R':
                r_queue.append(i)
            else:
                d_queue.append(i)
            
        
        while r_queue and d_queue:
            r_turn, d_turn = r_queue.popleft(), d_queue.popleft()
            
            if d_turn < r_turn:
                d_queue.append(d_turn + n)
            else:
                r_queue.append(r_turn + n)
        
        return "Radiant" if r_queue else "Dire"
            
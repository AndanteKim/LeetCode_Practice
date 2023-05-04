class Solution:
    def ban(self, to_ban: chr, start_at: int, senate: List[chr]) -> bool:
        loop_around = False
        pointer = start_at
        
        while True:
            if pointer == 0:
                loop_around = True
            if senate[pointer] == to_ban:
                senate.pop(pointer)
                break
            pointer = (pointer + 1) % len(senate)
        
        return loop_around
    
    def predictPartyVictory(self, senate: str) -> str:
        senate = list(senate)
        
        r_count = senate.count('R')
        d_count = len(senate) - r_count
        
        turn = 0
        while r_count > 0 and d_count > 0:
            if senate[turn] == 'R':
                banned_senator_before = self.ban('D', (turn + 1) % len(senate), senate)
                d_count -= 1
            else:
                banned_senator_before = self.ban('R', (turn + 1) % len(senate), senate)
                r_count -= 1
            
            if banned_senator_before:
                turn -= 1
            turn = (turn + 1) % len(senate)
        
        return 'Radiant' if d_count == 0 else 'Dire'
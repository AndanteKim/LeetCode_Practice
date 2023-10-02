class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        if len(colors) <= 2:
            return False
        
        a_options, b_options = 0, 0
        
        for i in range(1, len(colors) - 1):
            if colors[i - 1] == colors[i] == colors[i + 1]:
                if colors[i] == 'A':
                    a_options += 1
                else:
                    b_options += 1
        
        return False if a_options <= b_options else True
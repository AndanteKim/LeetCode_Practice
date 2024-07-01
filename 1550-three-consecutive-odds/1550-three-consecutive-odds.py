class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        combo = 0
        
        for n in arr:
            if n % 2:
                combo += 1
            else:
                combo = 0
                
            if combo == 3:
                return True
        return False
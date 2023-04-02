class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        ans, rows, cols = [], len(spells), len(potions)
        potions.sort()
        
        for i in range(rows):
            target = success / spells[i]
            ans.append(cols - bisect_left(potions, target))
            
        return ans
        
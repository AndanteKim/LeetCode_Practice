class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        ans = []
        potions.sort()
        total_potions = len(potions)
        
        for spell in spells:
            ans.append(total_potions - bisect_left(potions, success / spell))

        return ans
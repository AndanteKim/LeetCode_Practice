class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        return (len(potions) - bisect_left(potions, success, key = lambda p: p * s) for s in spells)
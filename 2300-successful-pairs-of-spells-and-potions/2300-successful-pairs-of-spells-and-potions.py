class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        ans, n = [], len(potions)
        potions.sort()
        
        for spell in spells:
            left, right = 0, len(potions)
            
            while left < right:
                mid = (left + right) >> 1
                if success <= potions[mid] * spell:
                    right = mid
                else:
                    left = mid + 1
            ans.append(n - left)
        return ans
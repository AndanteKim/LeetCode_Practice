class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        greatest = max(candies)
        
        return [True if candies[i] + extraCandies >= greatest else False for i in range(len(candies))]
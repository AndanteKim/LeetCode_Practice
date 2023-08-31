class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx_candies, ans = max(candies), [False] * len(candies)
        
        for i in range(len(candies)):
            if mx_candies <= extraCandies + candies[i]:
                ans[i] = True
        
        return ans
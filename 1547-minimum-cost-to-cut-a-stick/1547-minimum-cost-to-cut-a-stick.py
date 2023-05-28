class Solution:
    def cost(self, left: int, right: int, memo: Dict[int, int], cuts: List[int]) -> int:
        if (left, right) in memo:
            return memo[(left, right)]
        
        if right - left == 1:
            return 0
        ans = min(self.cost(left, mid, memo, cuts) + self.cost(mid, right, memo, cuts) + cuts[right] - cuts[left] for mid in range(left + 1, right))
        memo[(left, right)] = ans
        return ans
    
    def minCost(self, n: int, cuts: List[int]) -> int:
        memo = dict()
        cuts = [0] + sorted(cuts) + [n]
        
        return self.cost(0, len(cuts) - 1, memo, cuts)